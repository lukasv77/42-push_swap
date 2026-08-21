*This project has been created as part of the 42 curriculum by llinda, mmankows.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks (`a` and `b`) and a restricted
instruction set, and prints to standard output the sequence of operations that performs
the sort. The goal is not merely to sort — it is to sort using as few operations as
possible.

The program holds both stacks as circular doubly-linked lists and embeds **four
strategies**: a quadratic baseline, a `√n`-chunking method, a rank-based radix sort, and
an adaptive selector that measures how disordered the input is and dispatches to the
method whose complexity class fits that regime.

Available operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Instructions

### Build

```
make          # builds libft, ft_printf and the push_swap binary
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`. The Makefile does not relink.

### Usage

```
./push_swap [strategy] [--bench] <integers...>
```

Numbers may be passed as separate arguments, as a single quoted string, or as any
mixture of the two — all three forms below are equivalent:

```
./push_swap 5 4 3 2 1
./push_swap "5 4 3 2 1"
./push_swap "5 4" 3 "2 1"
```

### Flags

| Flag | Effect |
| --- | --- |
| `--simple` | Forces the O(n²) strategy |
| `--medium` | Forces the O(n√n) strategy |
| `--complex` | Forces the O(n log n) strategy |
| `--adaptive` | Forces the adaptive strategy (**default** when no selector is given) |
| `--bench` | Prints benchmark metrics to `stderr` after sorting |

Flags must appear **before** the list of integers.

### Examples

```
$> ./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
...

$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK

$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
5183
```

Benchmark mode writes to `stderr`, so the operation stream on `stdout` can still be
piped into the checker:

```
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 0 rb: 2 rr: 0 rra: 0 rrb: 1 rrr: 0
```

### Error handling

`Error` followed by a newline is written to `stderr`, and the program exits with `1`,
when an argument is not an integer, exceeds the `int` range, is an empty string, or
duplicates an earlier value:

```
$> ./push_swap 0 one 2 3
Error
$> ./push_swap 3 2 3
Error
$> ./push_swap 2147483648 1
Error
```

With no arguments at all, the program prints nothing and returns the prompt.

## Algorithms

### The complexity model

Every complexity stated below is measured in **the number of push_swap operations
emitted**, not in CPU time — this is the model the subject mandates. The distinction
matters for the Complex strategy in particular, and is discussed there.

### Disorder metric

Disorder is the normalized inversion count: the fraction of index pairs `(i, j)`, `i < j`,
for which `a[i] > a[j]`.

```
disorder = inversions / (n * (n - 1) / 2)
```

It is `0` for a sorted stack and `1` for a fully reversed one. It is computed once, on
the initial stack, **before any operation is emitted** (`main.c` calls
`calculate_disorder_percentage` before `run_strategy`). The implementation is the
straightforward double loop over the circular list — O(n²) CPU, but zero operations
emitted, so it does not affect the operation counts above.

`--bench` reports it as a percentage with two decimals.

### 1. Simple — insertion sort into stack `b` · O(n²)

Elements are moved one at a time from `a` into `b`, each inserted at its correct place so
that `b` is always kept sorted in descending order. To insert a value, `b` is rotated
until the insertion point reaches the top, the value is pushed with `pb`, and `b` is then
rotated back. Once `a` is empty, draining `b` back with `pa` yields `a` in ascending
order, since the top of `b` holds the largest remaining value.

`rotate_b_to_pos` chooses between `rb` and `rrb` depending on which direction is shorter,
which halves the constant factor but does not change the class: positioning one element
costs O(n) operations, and there are `n` elements.

- **Operations:** O(n²). Measured ≈ `0.39 n²` (3 872 ops at n = 100, 96 289 at n = 500).
- **Space:** O(n) for the nodes, O(1) auxiliary.

### 2. Medium — `√n` chunk sorting · O(n√n)

The stack is partitioned into `⌊√n⌋` chunks by **rank** (an element's position in the
sorted order), not by raw value — so the chunk boundaries are independent of how the
numbers are distributed.

`chunk_loop` walks `a` and, for each element on top:

- if its rank falls below the current window, `pb` then `rb` — pushing it to `b` and
  rotating it down out of the way;
- if its rank falls inside the current chunk window, `pb` — leaving it near the top;
- otherwise `ra`, deferring it to a later chunk.

Each of the `√n` chunks requires at most one full traversal of `a`, giving O(n) operations
per chunk and **O(n√n)** for the whole partitioning phase.

The drain phase repeatedly locates the maximum of `b` and rotates it to the top before
`pa`. Because the chunk pass leaves `b` in near-descending order, that maximum sits at or
near the top and the rotation cost per element is small in practice. A worst case that
forced a half-rotation for every element would degrade this phase to O(n²); the measured
counts show that case does not arise for chunked input.

- **Operations:** O(n√n). Measured 612 ops at n = 100 (bound `n√n` = 1 000) and ≈ 5 200 at
  n = 500 (bound ≈ 11 180).
- **Space:** O(n) for the nodes, O(1) auxiliary.

### 3. Complex — rank-based radix sort (LSD) · O(n log n)

Each element is identified by its **rank** in the sorted order — an integer in `[0, n)`.
Sorting the ranks sorts the values, and because ranks are always non-negative and bounded
by `n`, the radix sort needs exactly `⌈log₂ n⌉` passes and handles negative inputs,
`INT_MIN` and `INT_MAX` without any special case.

Pass `k` inspects bit `k` of each element's rank: a `0` bit sends the element to `b` with
`pb`, a `1` bit keeps it in `a` with `ra`. After the pass, everything in `b` is returned
with `pa`. Since the radix is 2 and the passes run least-significant bit first, the order
is stable and the stack is fully sorted after the final pass.

The operation bound is tight and easy to state: one pass performs exactly `n` iterations
emitting exactly one operation each, plus at most `n` `pa` instructions to drain `b` —
so at most `2n` operations per pass, and

```
total ≤ 2n · ⌈log₂ n⌉
```

- **Operations:** O(n log n). Measured 1 084 ops at n = 100 (bound 1 400) and 6 784 at
  n = 500 (bound 9 000).
- **Space:** O(n) for the nodes, O(1) auxiliary.

**A note on CPU time.** `get_rank` recomputes an element's rank by scanning both stacks,
which is O(n) per call and therefore O(n² log n) CPU time overall. In the push_swap model
this is irrelevant — ranks are computed in C and emit no operations — but it is a
deliberate trade-off: it buys a rank-based radix that needs no pre-sorted index array and
no extra allocation.

### 4. Adaptive — disorder-driven dispatch (default)

The adaptive strategy measures disorder once and dispatches:

| Disorder | Strategy selected | Complexity class |
| --- | --- | --- |
| `< 20 %` | Simple (insertion) | O(n²) |
| `20 % – 50 %` | Medium (chunking) | O(n√n) |
| `≥ 50 %` | Complex (radix) | O(n log n) |

**Rationale for the thresholds.** The three regimes match the complexity targets the
subject sets, and they follow the shape of the insertion cost curve. Disorder *is* the
normalized inversion count, and an insertion-based method pays almost exactly one
rotation per inversion — so at low disorder the O(n²) bound is never approached in
practice: few elements are misplaced, and each is found close to its insertion point. As
disorder grows, that relationship turns against insertion quadratically, and chunking —
whose cost depends on `n` alone rather than on how scrambled the input is — overtakes it.
Past 50 % the input is effectively random or reversed, no locality is left to exploit,
and only a method that ignores the initial arrangement entirely stays cheap; the radix
pass count depends on `n` alone.

- **Operations:** the bound of whichever strategy is selected.
- **Space:** O(n).

## Performance

Targets from the subject, and the counts this implementation produces with the default
(adaptive) strategy on random input:

| n | pass `<` | good `<` | excellent `<` | measured (adaptive) |
| --- | --- | --- | --- | --- |
| 100 | 2 000 | 1 500 | 700 | **612** |
| 500 | 12 000 | 8 000 | 5 500 | **5 183 – 6 784** |

Per-strategy counts on the same inputs:

| Strategy | n = 100 | n = 500 |
| --- | --- | --- |
| `--simple` | 3 872 | 96 289 |
| `--medium` | 612 | ≈ 5 200 |
| `--complex` | 1 084 | 6 784 |
| `--adaptive` | 612 | 5 183 – 6 784 |

The spread at n = 500 is a direct consequence of the threshold: uniformly random input
has an expected disorder of almost exactly 50 %, so measurements land on either side of
the Medium/Complex boundary from run to run, and the adaptive strategy follows.

Every configuration in the table was verified against `checker_linux`, and the binary
runs leak-free under `valgrind --leak-check=full`.

## Contributions

This is a two-person project. Both authors worked across the whole codebase; the split
below reflects primary ownership.

**mmankows**
- `main`, flag parsing and strategy dispatch
- Argument parsing, validation and error handling
- Disorder metric and `--bench` reporting
- Medium (`√n` chunking) and Complex (rank radix) strategies
- Adaptive thresholds and dispatch logic
- The push_swap operations instrumentation

**llinda**
- Stack representation (circular doubly-linked list) and list utilities
- The push_swap operations
- Simple (insertion) strategy
- Makefile, project headers and libft integration
- Stress testing and fixing bugs

Both authors reviewed and can explain every strategy in the binary.

## Resources

**Sorting and complexity**
- *Insertion Sort* — https://en.wikipedia.org/wiki/Insertion_sort
- *Radix sort* — https://en.wikipedia.org/wiki/Radix_sort
- Big-O notation — https://en.wikipedia.org/wiki/Big_O_notation

**Project references**
- The push_swap subject PDF (v1.1)
- `checker_linux`, the reference checker supplied with the subject
- The 42 Norm (v3)

**Use of AI**

AI assistance was used as a review and diagnostic aid, never as a code generator for
project logic. Specifically:

- *Debugging the argument parser.* Testing process exposed failures on mixed argument forms such
  as `./push_swap "5 4" 3 "2 1"`. AI was used to trace the fault to the parser's
  single-argument special case, and to talk through candidate fixes. Several proposals
  were rejected during that discussion for exceeding the Norm's limits on variables per
  function and functions per file; the design that was finally implemented — flattening
  all arguments into one string before a single `ft_split` — was chosen and written by
  the authors, having been the simplest of the options considered.
- *Edge-case review.* AI was used to identify parsing edge cases worth testing (empty
  string arguments, whitespace-only arguments, `INT_MIN`/`INT_MAX` boundaries), which were
  then verified by hand against `checker_linux`.

The sorting strategies, the disorder metric, the stack representation and the operation
set were designed and implemented without AI assistance. Both authors can explain and
defend every line of the submitted code.
