# cpcode
Competitive Programming Code

佛系刷题，题解通过脚本同步到博客。日常一条 `cb` 命令搞定编译/运行/对拍，
底层是一套跨 Mac/Linux 的 CMake 工作流。

## 快速上手（cb，日常推荐）

`cb` 是一个 shell 函数（`source tools/cb.sh`），在题目目录里**只写短名**：
它自动定位仓库、把短名翻译成完整 target、调用标准 cmake。装一次到处用。

```bash
# ① 安装（一次性，之后每个新 shell 都可用）
echo 'source '"$(pwd)"'/tools/cb.sh' >> ~/.zshrc && exec zsh

# ② 刷题（新建 cpp 不需要任何前置步骤，首条命令自动建构建树）
cd cf/contest/2003
cb A              # 编译
cb run-A          # 运行（stdin 直通，可手敲输入或 < in.txt）
cb test-A         # 编译 + 判样例（AC/WA/TLE/RE）
cb A D2 -j 8      # 多个目标 + 透传 flags
cb 2003           # 整场比赛一次全编（目录聚合）
cb stress gen brute A 1000 10   # 对拍：解析+编译三件套+开打
```

短名想写到哪一层都行：题目目录里 `cb A`，`cf/contest` 里 `cb 2003.A`，
仓库根 `cb 2003.A` / `cb 2003`；解析顺序 = 完整名 → cwd 前缀 → 全仓唯一
后缀；歧义时报候选清单（如根目录裸 `cb A`，补一层路径即可）。

### 用法总表（在 `cf/contest/2003/` 内）

| 命令 | 等价于 | 说明 |
|---|---|---|
| `cb A` | `cmake --build build -t cf.contest.2003.A` | 编译（增量） |
| `cb run-A` | `cmake --build build -t run-cf.contest.2003.A` | 运行，stdin 直通 |
| `cb test-A` | `cmake --build build -t test-cf.contest.2003.A` | 编译+判样例 |
| `cb A D2 -j 8` | 同上多个 target | 多目标，flags 透传 |
| `cb 2003` | `cmake --build build -t cf.contest.2003` | 目录聚合：整场全编 |
| `cb stress gen brute A 1000 10` | 解析+编译+`cmake -P stress.cmake` | 对拍，轮数/超时可省 |
| `cb cfg [-G Ninja ...]` | `cmake -S 仓库根 -B build` | 重配置；参数透传 |

### cb 的自动化行为

- **新文件免仪式**：新建 cpp 直接 `cb 新名`——查不到会自动静默重配置并重试
- **零树自举**：新克隆第一次 `cb X` 自动 `cmake -S -B` 建好构建树
- **位置无关**：仓库根用 `git rev-parse` 现算，无写死路径，多 clone/换机器通用
- **防呆**：在子目录执行 `cb cfg` 永远配置仓库根的树，不会像裸
  `cmake -B build` 那样把树建歪到当前目录

### cb 前提（缺一报错并指明缺什么）

| 前提 | 说明 |
|---|---|
| 在 git 仓库内 | 定位仓库根全靠 `git rev-parse` |
| cmake ≥ 3.20 | cb 转发的就是 cmake |
| C++ 编译器 | g++ / clang++ 均可，Mac 无 `bits/stdc++.h` 由仓库 shim 兜底 |
| bash 或 zsh | cb.sh 用了数组语法，POSIX `sh`/`dash` 不行 |
| 当前 shell source 过 | `cb` 是函数不是可执行文件，不进 PATH |

不是前提（常见误解）：不需要预先 `cmake -B build`，不需要站在仓库根。
可选：`ninja`（增量 0.06s 的 build-ninja 树）、`CP_BUILD_DIR`（指向非默认树）。

## 纯 cmake 命令（cb 的底层；脚本/CI 用）

cb 只是转发层，底下全是标准命令，任何地方可直接使用（`-t` 只认全名：
相对路径的 `/` 换成 `.`，完整对照表见 `build/target-map.tsv`）：

```bash
# 初始化（新增/删除 .cpp 后需要重跑；Ninja 树自动触发，Make 树需手动，
# 用 cb 则都可省——见上）
cmake -B build

# 编译一道题 / 一整个目录（每个含 cpp 的目录自动有同名聚合 target）
cmake --build build -t cf.contest.2003.A
cmake --build build -t cf.contest.2003

# 运行（stdin 直通终端：可交互手敲，也可以 < in.txt 重定向）
cmake --build build -t run-cf.contest.2003.A

# 测样例（构建 + 判该题全部样例；也可以直接用 ctest 按正则过滤）
cmake --build build -t test-cf.contest.2003.A
ctest --test-dir build -R 'judge[.]cf[.]contest[.]2003'

# 清理
cmake --build build -t clean       # 清构建产物
cmake -E rm -rf build              # 连构建系统一起删（全重置）

# 调试构建（-g -O0 -fsanitize=address,undefined）
cmake -B build-dbg -DCMAKE_BUILD_TYPE=Debug
cmake --build build-dbg -t cf.contest.2003.A

# 不想 source cb.sh 的最小替代
alias cb='cmake --build build -t'
alias ct='ctest --test-dir build -R'
```

## 对拍（随机数据 + 暴力 + 正解）

首选 `cb stress gen brute A 1000 10`（一条命令完成解析+编译+对拍）。
也可脱离 cb 单独用，gen/brute/sol 接受 target 名、短名或二进制路径：

```bash
# gen.cpp 读 argv[1] 当种子打印随机数据；brute.cpp 是暴力；sol 是待验解
cmake --build build -t tmp.stress                       # 目录聚合一次编齐
cmake -P cmake/stress.cmake tmp.stress.gen tmp.stress.brute tmp.stress.sol 1000 10
#                                                       iters┘    ┘单次超时秒数
```

gen 骨架：`template/stress/gen.cpp`（复制到题目目录，只改数据生成段）。

失配自动停：输入和两份输出保留在 `build/stress/fail_<n>/`，`last_input.txt`
是最近一轮的数据。判定口径与 judge 一致（忽略行尾空白/文末空行）。

## 样例约定

某道题的样例放在 `samples/` 子目录（随仓库同步，其余位置仍被 .gitignore
忽略），与 cpp 同名前缀配对：

```
cf/contest/2003/A.cpp
cf/contest/2003/samples/A_1.in   <- 与 A_1.out 配对
cf/contest/2003/samples/A_1.out
```

同目录的 `A.in`、`A_*.in` 也能被发现；单 cpp 目录里的 `in.txt` 兼容旧习惯。

## 其他

- 交互题双程序桥接：`bridge.sh`（保持原用法）
- 全仓库回归：`cmake --build build -t all-problems -j 8`（普通构建不会
  误触全量，裸 `cmake --build build` 是 no-op）
- 瘦身构建树（只编一场比赛）：`cmake -B build-fast -DCP_SCOPE=cf/contest/2003`
- target 名含中文/空格的文件会被转成下划线，反查 `build/target-map.tsv`
- 无 `main` 的片段（如 `template/slope/lichao.cpp`）自动降级为仅编译检查
- Ninja 可选：`cmake -B build-ninja -G Ninja`（增量更快，且新增 cpp 后无需
  手动 reconfigure，构建时自动重载）
- 同一套 CMake 在 Linux（g++ 原生 `bits/stdc++.h`）和 macOS（Apple clang，
  自动启用 `cmake/compat/bits/stdc++.h` shim）通用

## 已知编不过的历史文件（12 个）

`all-problems` 全量构建时这 12 个会报错——都是加入本构建系统**之前就坏了**
的旧代码（VLA 初始化、重复 main、Windows `_sleep` 等，在 Linux g++ 下同样
编不过），与 CMake 化无关：

```
atcode/contest/abc303/F.cpp     atcode/contest/abc305/G.cpp
atcode/contest/abc357/D.cpp     atcode/contest/abc361.C.cpp
cf/a-problem-everyday/2023/06/29/621E.cpp
cf/a-problem-everyday/2024/03/08/1196D1.cpp
cf/contest/1457/C.cpp           cf/contest/1621/B.cpp
cf/contest/1654/D.cpp           cf/contest/1934/A.cpp
cf/contest/1937/A.cpp           template/astar/astar.cpp
```
