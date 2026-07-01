#!/bin/bash
# 用法: ./bridge.sh <程序A路径> <程序B路径>
# 示例: ./bridge.sh ./my_client ./my_server

# --- 1. 参数检查 ---
if [ $# -ne 2 ]; then
    echo "错误：请提供两个程序路径"
    echo "用法: $0 <程序A（发问方）> <程序B（应答方）>"
    exit 1
fi

# 获取程序路径（支持相对/绝对路径，带空格也能处理）
A_CMD="$1"
B_CMD="$2"

# 检查文件是否存在且可执行
if [ ! -x "$A_CMD" ]; then
    echo "错误：程序A '$A_CMD' 不存在或不可执行"
    exit 1
fi
if [ ! -x "$B_CMD" ]; then
    echo "错误：程序B '$B_CMD' 不存在或不可执行"
    exit 1
fi

# 提取纯文件名（用于日志标签）
A_NAME=$(basename "$A_CMD")
B_NAME=$(basename "$B_CMD")

# --- 2. 创建命名管道 ---
PIPE_AB="fifo_${A_NAME}_to_${B_NAME}"
PIPE_BA="fifo_${B_NAME}_to_${A_NAME}"
rm -f "$PIPE_AB" "$PIPE_BA"
mkfifo "$PIPE_AB" "$PIPE_BA"

# 清理函数（退出时自动执行）
cleanup() {
    echo "清理管道..."
    exec 3>&- 4>&- 2>/dev/null
    rm -f "$PIPE_AB" "$PIPE_BA"
    exit
}
trap cleanup EXIT INT TERM

# --- 3. 预打开管道（解决 open 阻塞）---
exec 3<> "$PIPE_AB"   # A->B
exec 4<> "$PIPE_BA"   # B->A

# --- 4. 启动日志文件（可选）---
LOG_FILE="interaction.log"
> "$LOG_FILE"  # 清空旧日志
echo "交互开始，日志保存到 $LOG_FILE" >&2
echo "程序A: $A_NAME (发问方)" >&2
echo "程序B: $B_NAME (应答方)" >&2
echo "按 Ctrl+C 终止..." >&2

# --- 5. 启动两个程序（带 tee 分流）---
# A 的输出 -> 发给 B 的同时，打印带标签 + 存日志
"$A_CMD" <&4 | tee >(tee -a "$LOG_FILE" | sed -u "s/^/[${A_NAME}] /" > /dev/tty) >&3 &
PID_A=$!

# B 的输出 -> 发给 A 的同时，打印带标签 + 存日志
"$B_CMD" <&3 | tee >(tee -a "$LOG_FILE" | sed -u "s/^/[${B_NAME}] /" > /dev/tty) >&4 &
PID_B=$!

# --- 6. 等待进程结束 ---
wait $PID_A $PID_B

echo "交互结束" >&2