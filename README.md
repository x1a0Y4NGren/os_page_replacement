# 迁移提示

本仓库已迁移至 `course-labs/operating-system/page-replacement`，当前仓库仅作历史存档，不再维护。后续更新请查看 course-labs 仓库。

# 页式虚拟存储管理实验

本项目用于操作系统课程“页式虚拟存储管理”实验。项目依据根目录下的实验报告书 `2-页式虚拟存储管理实验报告-第2组-组员姓名.docx` 建立，使用 C 语言模拟页式虚拟存储管理过程，比较 OPT、FIFO、LRU 和扩展 CLOCK 页面置换算法在不同访问序列、不同内存页框数下的命中率。

项目按 Linux/WSL 下 C 语言实验环境组织，不使用第三方库。

## 实验功能

- 生成 320 条指令序列，指令地址范围为 0 到 319。
- 将指令序列转换为页地址流，每页包含 10 条指令，虚拟页号范围为 0 到 31。
- 设置用户虚存容量为 32 页。
- 设置用户内存容量从 4 到 32 个 page frame。
- 实现并比较 OPT、FIFO、LRU 三种基础页面置换算法。
- 支持 25%、50%、75% 三种顺序执行比例对比。
- 实现随机页地址流、循环页地址流扩展实验。
- 实现 CLOCK / Second Chance 改进算法，并与 OPT、FIFO、LRU 对比。
- 保存 Linux/WSL 运行结果和实验图表，便于整理实验报告。

## 编译运行

在 Linux 或 WSL 环境下执行：

```bash
make
make run
```

清理编译产物：

```bash
make clean
```

正式实验数据以 Linux/WSL 下 `make run` 输出为准，完整输出已保存到 `results/linux_make_run.txt`。

程序默认输出：

- 25%、50%、75% 三组顺序执行比例下，页框数 4 到 32 对应的 OPT、FIFO、LRU 命中率；
- 随机页地址流下 OPT、FIFO、LRU、CLOCK 的命中率；
- 循环页地址流下 OPT、FIFO、LRU、CLOCK 的命中率。

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
│   ├── extension_ethics.md
│   └── team_tasks.md
├── pictures/
│   ├── hit_rates_25.png
│   ├── hit_rates_50.png
│   ├── hit_rates_75.png
│   ├── hit_rates_opt_ratio_comparison.png
│   ├── hit_rates_fifo_ratio_comparison.png
│   ├── hit_rates_lru_ratio_comparison.png
│   └── report_flowchart.png
└── results/
    ├── .gitkeep
    └── linux_make_run.txt
```

## 成员分工

| 成员 | 负责文件 | 主要职责 |
| --- | --- | --- |
| A | `src/main.c`, `include/common.h`, `Makefile`, `README.md`, `.gitignore` | 负责主函数、模块调用、项目结构、编译脚本、GitHub 管理和最终整合 |
| B | `src/algorithms.c`, `include/algorithms.h`, `docs/algorithm_notes.md` | 负责 OPT、FIFO、LRU 页面置换算法及算法分析 |
| C | `src/sequence.c`, `include/sequence.h`, `docs/experiment_analysis.md` | 负责指令序列生成、页地址流转换、基础实验数据整理和图表分析 |
| D | `src/extension.c`, `include/extension.h`, `docs/extension_ethics.md` | 负责随机序列、循环序列、CLOCK 改进算法、扩展实验和科技伦理思考 |

## 文档与结果

- `docs/algorithm_notes.md`：记录 OPT、FIFO、LRU 算法原理、接口、优缺点和性能分析。
- `docs/experiment_analysis.md`：记录指令序列生成方式、页地址流转换方式、基础实验数据、图表说明和结论。
- `docs/extension_ethics.md`：记录随机序列、循环序列、CLOCK 改进算法、扩展实验分析和科技伦理思考。
- `results/linux_make_run.txt`：保存 Linux/WSL 环境下的完整运行输出。
- `pictures/`：保存基础实验图表和实验报告流程图。

## Git 协作建议

1. 修改前先执行 `git pull` 获取最新代码。
2. 每位成员原则上只修改自己负责的文件，减少合并冲突。
3. 提交前在 Linux/WSL 下执行 `make clean && make && make run`。
4. 不提交 `build/`、`bin/`、可执行文件和 IDE 缓存。
5. 提交信息应简洁说明修改内容，例如 `B: update algorithm notes`。

## 当前状态

项目代码、基础实验、扩展实验、结果文件、图表和 Markdown 文档均已按最终实验状态对齐。实验报告可根据 `docs/`、`results/linux_make_run.txt` 和 `pictures/` 中的内容整理提交。
