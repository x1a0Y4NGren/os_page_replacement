# 操作系统实验 2 小组后续任务安排

## 一、当前项目状态

当前项目已经完成以下基础工作：

- GitHub 项目框架已经建立；
- 基础实验主流程已经能通过 gcc 编译运行；
- 已包含 320 条指令序列生成；
- 已包含页地址流转换；
- 已包含 OPT、FIFO、LRU 三种算法；
- 已支持 25%、50%、75% 顺序执行比例对比；
- 扩展任务和实验报告文档仍需补充。

当前项目的主要缺口：

- 扩展任务没有完整输出统计表；
- 改进算法目前只是占位；
- docs 中的数据分析、图表、结论、伦理思考还需要补充；
- 需要最终在 Linux 或支持 make 的环境下验证 make 和 make run。

请各成员原则上只修改自己负责的文件，避免 Git 冲突。修改前先 pull 最新代码，修改后提交到自己的分支，或按组长要求提交。

## 二、成员 A 后续任务

A 是组长，主要负责主函数、项目整合和 GitHub 管理。

负责文件：

- src/main.c
- include/common.h
- Makefile
- README.md
- .gitignore

需要完成：

1. 维护 main.c 的整体实验流程。
2. 保证其他成员的函数能被 main.c 正确调用。
3. 等 D 完成扩展任务后，把随机序列、循环序列、改进算法的实验输出整合进 main.c。
4. 检查 Makefile 是否能在 Linux 环境下正常执行 make、make run、make clean。
5. 负责 GitHub 仓库管理、分支合并、最终版本检查和提交。
6. 不负责继续实现 OPT/FIFO/LRU 核心算法，也不负责具体数据分析正文。

## 三、成员 B 后续任务

B 主要负责页面置换算法和算法分析。

负责文件：

- src/algorithms.c
- include/algorithms.h
- docs/algorithm_notes.md

需要完成：

1. 检查 OPT、FIFO、LRU 三种算法实现是否正确。
2. 检查三个接口是否保持不变：
   - double run_opt(const int pages[], int n, int frame_count);
   - double run_fifo(const int pages[], int n, int frame_count);
   - double run_lru(const int pages[], int n, int frame_count);
3. 补充 docs/algorithm_notes.md 中的算法原理说明。
4. 补充 OPT、FIFO、LRU 的优缺点比较。
5. 结合程序输出结果，分析不同 frame 数量下三种算法命中率变化趋势。
6. 不要随意修改 main.c，避免和组长整合冲突。

## 四、成员 C 后续任务

C 主要负责指令序列生成、实验数据整理和基础实验分析。

负责文件：

- src/sequence.c
- include/sequence.h
- docs/experiment_analysis.md

需要完成：

1. 检查 320 条指令序列生成逻辑是否符合实验要求。
2. 检查指令地址到页号的转换是否正确，即 page = instruction / 10。
3. 确认 25%、50%、75% 顺序执行比例都能正常生成并参与测试。
4. 将程序运行得到的基础实验结果整理到 docs/experiment_analysis.md。
5. 补充不同顺序执行比例下 OPT、FIFO、LRU 的命中率对比表。
6. 根据实验数据补充图表说明和结论。
7. 如果发现当前序列生成方式与实验报告书原始六步描述不完全一致，需要记录并和组长确认是否调整。
8. 不要随意修改 algorithms.c 和 main.c。

## 五、成员 D 后续任务

D 主要负责扩展任务、改进算法和科技伦理思考。

负责文件：

- src/extension.c
- include/extension.h
- docs/extension_ethics.md

需要完成：

1. 完善随机序列生成函数。
2. 完善循环序列生成函数。
3. 让扩展任务能够输出 frame 4 到 32 下 OPT、FIFO、LRU 的完整命中率统计表。
4. 如选择实现改进算法，建议实现 CLOCK / Second Chance 页面置换算法。
5. 如果不实现真正的新算法，需要在文档中明确说明 run_improved_algorithm 只是预留接口，不作为最终实验结论。
6. 补充 docs/extension_ethics.md 中的扩展实验结果。
7. 分析随机序列、循环序列和普通局部性序列的命中率差异。
8. 完成科技伦理思考，结合 Web 服务器内存压力、页面置换算法选择、系统稳定性、资源公平性、用户体验等角度展开。
9. 不要随意修改 main.c，扩展任务完成后通知组长整合。

## 六、提交规范

Git 协作要求：

1. 修改前先 pull 最新代码。
2. 每个人只改自己负责的文件。
3. 每次提交前确认项目还能编译。
4. commit message 要写清楚做了什么。
5. 不要提交 bin/、exe、临时文件、IDE 缓存。
6. 完成后通知组长进行合并和最终测试。

## 七、最终目标

最终需要完成：

- C 程序可编译运行；
- 基础实验和扩展实验都有输出结果；
- docs 中的算法说明、实验分析、扩展分析、伦理思考完整；
- GitHub 仓库结构清晰；
- 实验报告可以根据代码、输出和 docs 内容整理完成。
