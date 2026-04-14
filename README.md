*This project has been created as part of the 42 curriculum by ausmanov, aousmano.*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project. Given a stack of integers, the program outputs the shortest sequence of operations needed to sort them in ascending order (smallest at top), using two stacks `a` and `b` and eleven allowed operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

The project requires implementing four distinct sorting strategies selected automatically or via flags.

## Instructions

### Compilation

```bash
make        # builds push_swap
make clean  # removes object files
make fclean # removes object files and binary
make re     # full rebuild
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

**Strategy flags (optional, default is --adaptive):**
- `--simple`   — O(n²) selection sort
- `--medium`   — O(n√n) chunk-based sort
- `--complex`  — O(n log n) LSD radix sort
- `--adaptive` — selects strategy based on measured disorder

**Benchmark flag:**
- `--bench` — prints to stderr: disorder %, strategy used, total ops, per-op counts

**Examples:**

```bash
./push_swap 5 3 1 4 2
./push_swap --simple 5 3 1 4 2
./push_swap --bench --adaptive 5 3 1 4 2
./push_swap --bench --complex 5 3 1 4 2 2>/dev/null | wc -l
```

**Error cases (prints `Error` to stderr and exits):**
```bash
./push_swap 1 two 3     # non-integer argument
./push_swap 1 2 2       # duplicate values
./push_swap 99999999999 # out of int range
```

## Algorithms

### Disorder metric

Before sorting, a disorder value in [0, 1] is computed:

```
disorder = (number of inverted pairs) / (total pairs)
```

An inverted pair is any (i, j) where i < j but a[i] > a[j]. Disorder 0 = already sorted, disorder 1 = worst case.

### Strategy 1 — Simple O(n²): Selection sort

Repeatedly finds the minimum of stack `a`, rotates it to the top (`ra`/`rra`), pushes it to `b`. Once `a` is sorted, pushes everything back from `b` to `a`.

- Stops as soon as `a` is sorted (early exit).
- For low-disorder inputs (< 0.2), this effectively runs in O(n) operations since sorted condition is reached after pushing very few elements.

### Strategy 2 — Medium O(n√n): Chunk-based sort

Assigns a rank to each element (0 = smallest). Divides ranks into chunks of size √n. Pushes each chunk to `b` in order. Then pops back to `a` by always pushing the current maximum of `b`.

- `ft_assign_ranks`: O(n²) internal, but 0 push_swap operations.
- Push phase: O(n√n) rotations to find elements per chunk.
- Pop phase: O(n√n) rotations to find max in `b` per element.

### Strategy 3 — Complex O(n log n): LSD Radix sort

Assigns ranks then sorts by bits from least significant to most significant. Each pass: elements with current bit = 0 are pushed to `b`, elements with bit = 1 are rotated to bottom of `a`. Then all of `b` is pushed back on top of `a`. After log₂(n) passes, `a` is sorted.

- log₂(n) passes × n operations per pass = O(n log n).
- Ranks are preserved through `pb`/`pa` to ensure correctness across passes.

### Strategy 4 — Adaptive: selects by disorder

| Disorder         | Size condition | Strategy used     | Complexity  |
|------------------|----------------|-------------------|-------------|
| < 0.2            | any            | Simple (early exit) | O(n) in practice |
| 0.2 ≤ d < 0.5   | n ≤ 50         | Chunk sort        | O(n√n)      |
| 0.2 ≤ d < 0.5   | n > 50         | LSD Radix sort    | O(n log n)  |
| ≥ 0.5            | any            | LSD Radix sort    | O(n log n)  |

**Rationale for thresholds:**
- Below 0.2: stack is nearly sorted. Selection sort stops very early.
- 0.2–0.5 with small n: moderate disorder and small input. Chunk sort balances passes well.
- 0.2–0.5 with large n: chunk sort degrades to O(n√n) with large constants; radix dominates.
- Above 0.5: high disorder. Radix sort's guaranteed O(n log n) dominates.

## Performance targets

| Input size | Pass    | Good    | Excellent |
|------------|---------|---------|-----------|
| 100 nums   | < 2000  | < 1500  | < 700     |
| 500 nums   | < 12000 | < 8000  | < 5500    |

## Resources

- Knuth, D. (1998). *The Art of Computer Programming, Vol. 3: Sorting and Searching*.
- Cormen et al. — *Introduction to Algorithms* (CLRS), Chapter 8: Linear Time Sorting (Radix Sort).
- Wikipedia — [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- Wikipedia — [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
- push_swap visualizer: [https://github.com/o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

### AI usage

AI (Claude) was used during this project for:
- Identifying bugs in the radix sort implementation (rank preservation, direction of passes).
- Debugging the adaptive strategy's potential infinite loop in nearly-sorted case.
- Reviewing multi-flag argument parsing logic.

All AI-suggested fixes were reviewed, tested, and understood before integration.

## Contributors

| Login    | Contributions                                      |
|----------|----------------------------------------------------|
| ausmanov | Did the algorithms code and the basic verifs.      |
|          | and did the main too with my mate                  |
| aousmano | Did the codes for the operations and the main was  |
|          | done by the two of us                              |
