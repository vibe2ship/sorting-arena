# Sorting Arena

**Optimize a C sorting algorithm with AI. May the fastest implementation win.**

A vibe coding hackathon by [Vibe2Ship](https://github.com/vibe2ship).

## Rules

1. **Implement one function**: `void participant_sort(int *arr, size_t n)`
2. **Language**: Pure C (C11), no external dependencies
3. **Constraints**: Must produce correct output; extra memory usage capped at O(n)
4. **AI is fair game** — use whatever tools you like

## Getting Started

```bash
git clone https://github.com/vibe2ship/sorting-arena.git
cd sorting-arena

# Run the baseline to see what you're up against
make run

# Write your implementation
vim submissions/example/sort.c

# Run again and check your results
make run
```

## Benchmarking

Your implementation is benchmarked against glibc `qsort`.

Local tests use random data at `1K` and `10K` elements. The final evaluation runs at larger scales.

## Sample Output

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

## How to Submit

1. Fork this repository
2. Create your directory under `submissions/`: `submissions/your-name/sort.c`
3. Implement `participant_sort`
4. Make sure `make run SUBMISSION=submissions/your-name/sort.c` passes all checks
5. Open a pull request

## Project Structure

```
sorting-arena/
├── include/
│   └── arena.h                  # Public header: timing, data generation, validation
├── src/
│   ├── benchmark.c              # Benchmark driver
│   └── baseline.c               # qsort baseline
├── submissions/
│   └── example/
│       └── sort.c               # Starter template (begin here)
├── Makefile                     # One-command benchmarking via make run
└── README.md
```

## FAQ

**Q: Can I use AI?**
A: Absolutely. Go wild.

**Q: How is the winner decided?**
A: The benchmark has the final say.

---

Vibe2Ship · Building in the age of AI
