# Sorting Arena

**用 AI 优化 C 语言排序算法，看谁跑得最快。**

A vibe coding hackathon by [Vibe2Ship](https://github.com/vibe2ship).

## 规则

1. **实现一个函数**：`void participant_sort(int *arr, size_t n)`
2. **语言**：纯 C（C11），不依赖外部库
3. **要求**：结果正确，额外内存不超过 O(n)
4. **AI 随便用**

## 快速开始

```bash
git clone https://github.com/vibe2ship/sorting-arena.git
cd sorting-arena

# 跑一下 baseline，感受一下
make run

# 编辑你的实现
vim submissions/example/sort.c

# 再跑一次，看你的成绩
make run
```

## 评测方式

你的实现会和 glibc `qsort` 对比。

本地测试：随机数据，`1K` 和 `10K`。最终评测规模更大。

## 输出示例

```
  ┌─────────────────────────────────────────────────────────────┐
  │              Sorting Arena  ·  Benchmark                     │
  │              Vibe2Ship Hackathon                            │
  └─────────────────────────────────────────────────────────────┘

  █ qsort (reference)    █ participant (you)

  ━━ 10K (10000 elements) 1.59x faster

  qsort       ████████████████████████████████████████      0.57 ms
  participant █████████████████████████                      0.36 ms  ◀
```

## 提交方式

1. Fork 本仓库
2. 在 `submissions/` 下创建你的目录：`submissions/你的名字/sort.c`
3. 实现 `participant_sort`
4. 确保 `make run SUBMISSION=submissions/你的名字/sort.c` 全部 PASS
5. 提交 PR

## 项目结构

```
sorting-arena/
├── include/
│   └── arena.h                  # 公共头文件：计时、数据生成、验证
├── src/
│   ├── benchmark.c              # 评测主程序
│   └── baseline.c               # qsort baseline
├── submissions/
│   └── example/
│       └── sort.c               # 示例模板（从这里开始）
├── Makefile                     # make run 一键评测
└── README.md
```

## FAQ

**Q: 可以用 AI 吗？**
A: 随便用。

**Q: 怎么算赢？**
A: benchmark 说了算。

---

Vibe2Ship · AI 时代的产品实验室
