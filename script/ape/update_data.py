"""拉取 Codeforces 题库数据，供 gen_ape.py 使用的题库数据源。

调用 Codeforces 官方 API problemset.problems，取回全量题目列表与提交
统计，抽取 problems / problemStatistics 两个字段后写入本地 JSON 文件
（默认 script/ape/cf-all.json，与 gen_ape.py 共用同一份数据）。
建议在新增比赛后跑一次以刷新数据。

用法:
    # 使用默认输出路径 script/ape/cf-all.json
    python3 script/ape/update_data.py

    # 指定输出文件（父目录不存在会自动创建）
    python3 script/ape/update_data.py -o /tmp/cf-all.json

参数 / 退出行为:
    -o, --output PATH  覆盖默认输出路径，任意目录下运行均可
    成功时打印 update data success 并退出码 0
    网络失败或 API 返回非 OK 时打印中文错误（含 status/remark），退出码 1，
    且不会写出半截文件
"""

import argparse
import json
import sys

import requests
from pathlib import Path

# 路径锚点：默认输出锚定脚本所在目录，不依赖当前工作目录
SCRIPT_DIR = Path(__file__).resolve().parent   # …/cpcode/script/ape

# CF 题库数据文件默认落在 script/ape/cf-all.json
DEFAULT_OUTPUT = SCRIPT_DIR / "cf-all.json"

API_URL = "https://codeforces.com/api/problemset.problems"


def parse_args():
    parser = argparse.ArgumentParser(
        description="拉取 Codeforces 题库 API，更新本地 cf-all.json "
                    "（供 gen_ape.py 使用）。",
        epilog="用法示例:\n"
               "  python3 script/ape/update_data.py                # 写入默认路径 script/ape/cf-all.json\n"
               "  python3 script/ape/update_data.py -o /tmp/a.json # 指定输出文件",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "-o", "--output", metavar="PATH", default=str(DEFAULT_OUTPUT),
        help="输出 JSON 文件路径（默认: %(default)s），父目录不存在时自动创建")
    return parser.parse_args()


def main():
    args = parse_args()

    # 请求官方 API，网络异常直接报错退出，不碰输出文件
    try:
        rsp = json.loads(requests.get(url=API_URL).text)
    except requests.RequestException as e:
        print("请求 Codeforces API 失败: {}".format(e))
        sys.exit(1)
    except json.JSONDecodeError as e:
        print("Codeforces API 返回的不是合法 JSON: {}".format(e))
        sys.exit(1)

    if rsp.get('status') != "OK":
        # API 明确返回失败，带出 status/remark 便于排查
        print("Codeforces API 返回失败: status={}, remark={}".format(
            rsp.get('status'), rsp.get('remark', '(无 remark)')))
        sys.exit(1)

    # 先在内存里组装完整数据，再一次写盘，避免写半截文件
    data = {"problemStatistics": rsp["result"]["problemStatistics"],
            "problems": rsp["result"]["problems"]}

    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    with open(output, "w", encoding="utf8") as f:
        json.dump(data, f)

    print("update data success")


if __name__ == "__main__":
    main()
