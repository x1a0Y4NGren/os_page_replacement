# 操作系统实验 2 小组最终状态与分工说明

## 一、当前项目状态

当前项目已经完成最终整合，主要内容包括：

- GitHub 项目框架已经建立；
- C 程序可以在 Linux/WSL 环境下通过 `make` 编译，并通过 `make run` 运行；
- 已生成 320 条指令序列，并转换为页地址流；
- 已实现 OPT、FIFO、LRU 三种基础页面置换算法；
- 已支持 25%、50%、75% 三种顺序执行比例对比；
- 已实现随机页地址流、循环页地址流扩展实验；
- 已实现 CLOCK / Second Chance 改进算法；
- 已保存完整运行结果到 `results/linux_make_run.txt`；
- 已生成基础实验图表和程序流程图；
- Markdown 文档已按最终项目状态对齐，可用于整理实验报告。

## 二、成员 A 完成情况

A 是组长，负责主函数、项目整合和 GitHub 管理。

负责文件：

- `src/main.c`
- `include/common.h`
- `Makefile`
- `README.md`
- `.gitignore`

已完成内容：

1. 维护主函数和整体实验流程。
2. 调用 B、C、D 成员提供的统一接口。
3. 整合基础实验和扩展实验输出。
4. 保证项目支持 `make`、`make run`、`make clean`。
5. 负责最终文档对齐、提交和 push。

## 三、成员 B 完成情况

B 负责页面置换算法和算法分析。

负责文件：

- `src/algorithms.c`
- `include/algorithms.h`
- `docs/algorithm_notes.md`

已完成内容：

1. 实现 `run_opt`、`run_fifo`、`run_lru` 三个统一接口。
2. 完成 OPT、FIFO、LRU 算法原理说明。
3. 补充三种算法优缺点和性能分析。
4. 结合 Linux/WSL 运行结果分析不同 frame 数量下的命中率变化。

## 四、成员 C 完成情况

C 负责指令序列生成、页地址流转换和基础实验分析。

负责文件：

- `src/sequence.c`
- `include/sequence.h`
- `docs/experiment_analysis.md`

已完成内容：

1. 实现 320 条指令序列生成。
2. 支持 25%、50%、75% 顺序执行比例。
3. 实现 `page = instruction / 10` 的页地址流转换。
4. 整理基础实验结果、图表说明和实验结论。
5. 生成并维护基础实验图表文件。

## 五、成员 D 完成情况

D 负责扩展任务、改进算法和科技伦理思考。

负责文件：

- `src/extension.c`
- `include/extension.h`
- `docs/extension_ethics.md`

已完成内容：

1. 实现随机页地址流生成。
2. 实现循环页地址流生成。
3. 实现 CLOCK / Second Chance 改进算法。
4. 输出随机序列和循环序列下 OPT、FIFO、LRU、CLOCK 的完整命中率统计表。
5. 补充扩展实验分析和科技伦理思考。

## 六、最终提交规范

后续如果还需要修改，请遵守以下要求：

1. 修改前先 `git pull` 最新代码。
2. 每位成员原则上只修改自己负责的文件。
3. 提交前在 Linux/WSL 下运行 `make clean && make && make run`。
4. 不提交 `build/`、`bin/`、可执行文件、临时文件和 IDE 缓存。
5. commit message 应说明修改内容。
6. 修改完成后通知组长进行最终检查和合并。

## 七、最终目标完成情况

项目当前已经达到最终提交前状态：

- C 程序可编译运行；
- 基础实验和扩展实验均有输出结果；
- docs 中算法说明、实验分析、扩展分析、伦理思考均已补充；
- GitHub 仓库结构清晰；
- 实验报告可以依据代码、输出、图表和 Markdown 文档整理完成。
