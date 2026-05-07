# 页式虚拟存储管理实验

本项目用于操作系统课程“页式虚拟存储管理”实验。项目根据根目录下的实验报告书 `2-页式虚拟存储管理实验报告-第2组-组员姓名.docx` 生成，模拟 320 条指令序列转换为页地址流，并比较 OPT、FIFO、LRU 三种页面置换算法在不同内存页框数下的命中率。

## 实验内容

- 生成 320 条指令序列。
- 将指令序列转换为 32 页虚拟页地址流，每页包含 10 条指令。
- 用户虚存容量为 32 页。
- 用户内存容量从 4 到 32 个 page frame。
- 比较 OPT、FIFO、LRU 页面置换算法命中率。
- 支持 25%、50%、75% 顺序执行比例对比。
- 扩展随机序列、循环序列和改进算法接口。

## 编译运行

Linux 环境下执行：

```bash
make
make run
```

清理编译产物：

```bash
make clean
```

程序默认输出 25%、50%、75% 三组顺序执行比例下，页框数 4 到 32 对应的 OPT、FIFO、LRU 命中率表格，方便复制到实验报告中。

## 文件结构

```text
.
├── README.md
├── Makefile
├── .gitignore
├── include/
│   ├── common.h
│   ├── algorithms.h
│   ├── sequence.h
│   └── extension.h
├── src/
│   ├── main.c
│   ├── algorithms.c
│   ├── sequence.c
│   └── extension.c
├── docs/
│   ├── algorithm_notes.md
│   ├── experiment_analysis.md
│   └── extension_ethics.md
└── results/
    └── .gitkeep
```

## 成员分工

| 成员 | 负责文件 | 主要职责 |
| --- | --- | --- |
| A | `src/main.c`, `include/common.h`, `Makefile`, `README.md`, `.gitignore` | 组长，负责主函数、模块调用、GitHub 项目框架、编译脚本和整体流程控制 |
| B | `src/algorithms.c`, `include/algorithms.h`, `docs/algorithm_notes.md` | 实现 OPT、FIFO、LRU 页面置换算法，撰写算法原理和性能分析 |
| C | `src/sequence.c`, `include/sequence.h`, `docs/experiment_analysis.md` | 生成指令序列，转换页地址流，整理实验数据、图表说明和结论 |
| D | `src/extension.c`, `include/extension.h`, `docs/extension_ethics.md` | 实现随机序列、循环序列、改进算法接口，撰写扩展分析和科技伦理思考 |

## Git 协作建议

1. 每位成员原则上只修改自己负责的文件，降低合并冲突。
2. 修改前先 `git pull`，提交前先本地执行 `make clean && make && make run`。
3. 提交信息建议写清楚模块，例如 `B: implement lru algorithm`。
4. 实验结果可保存到 `results/` 目录，例如 `results/default_50.txt`。
5. 报告书 `.docx` 是任务要求来源，不在代码开发过程中修改。
