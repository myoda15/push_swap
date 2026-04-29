*This project has been created as part of the 42 curriculum by mande-so.*

# Push Swap

## Description

Push Swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (A and B) and a limited set of operations, while minimizing the total number of moves.

The program `push_swap` receives a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order on stack A.

The challenge lies in finding efficient strategies for different input sizes — from trivial 2-element cases up to 500+ numbers — where performance is directly graded.

## Instructions

### Compilation

```bash
make        # compiles push_swap
make clean  # removes object files
make fclean # removes object files and executables
make re     # recompiles everything from scratch
```

### Usage

```bash
./push_swap 3 2 1 5 4
```

The program prints each operation to stdout, one per line:

```
pb
pb
sa
pa
pa
```

To verify the output is correct, pipe it into the checker:

```bash
./push_swap 3 2 1 5 4 | ./checker_Mac 3 2 1 5 4
# OK
```

### Error Handling

The program outputs `Error` to stderr and exits with code 1 for:

```bash
./push_swap a 1 2        # non-numeric argument
./push_swap 1 2 2        # duplicate values
./push_swap 2147483648   # integer overflow
```

It exits silently (code 0) for:

```bash
./push_swap              # no arguments
./push_swap 1 2 3        # already sorted
```

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | swap the first two elements of stack A |
| `sb` | swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | push top of stack B onto stack A |
| `pb` | push top of stack A onto stack B |
| `ra` | rotate stack A upward (first element goes to bottom) |
| `rb` | rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | reverse rotate stack A (last element goes to top) |
| `rrb` | reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithm Overview

Different strategies are used depending on input size:

- **2 numbers** — swap if needed
- **3 numbers** — hardcoded optimal solution covering all 6 permutations
- **4–5 numbers** — move the smallest element(s) to stack B, sort the remaining 3, push back
- **6+ numbers** — radix sort using binary representation of indexed values

### Radix Sort (6+ numbers)

1. Each number is assigned an **index** from 0 to N-1 based on its relative rank
2. The sort processes each bit from LSB to MSB
3. For each bit: elements with bit=0 are pushed to B, elements with bit=1 are rotated to the bottom of A
4. After each bit pass, everything in B is pushed back to A
5. After all bits are processed, stack A is sorted

### Performance

| Input size | Operations | Score |
|------------|------------|-------|
| 100 numbers | ~1084 ops | 3/5 points |
| 500 numbers | ~6784 ops | 4/5 points |

Grading thresholds for reference:

| 100 numbers | 500 numbers | Points |
|-------------|-------------|--------|
| < 700 ops | < 5500 ops | 5/5 |
| < 900 ops | < 7000 ops | 4/5 |
| < 1100 ops | < 8500 ops | 3/5 |

## Project Structure

```
push_swap/
├── Makefile
├── push_swap.h
├── libft/                      # Custom C library
└── srcs/
    ├── main.c                  # Entry point
    ├── error.c                 # Error handling
    ├── parsing.c               # Input validation
    ├── init.c                  # Stack initialization
    ├── operations/
    │   ├── swap.c              # sa, sb, ss
    │   ├── push.c              # pa, pb
    │   ├── rotate.c            # ra, rb, rr
    │   └── reverse_rotate.c   # rra, rrb, rrr
    ├── algorithm/
    │   ├── sort_small.c        # 2–3 elements
    │   ├── sort_medium.c       # 4–5 elements
    │   └── sort_large.c        # 6+ elements (radix sort)
    └── utils/
        ├── stack_utils.c       # node creation, list manipulation
        └── utils.c             # is_sorted, find_min, find_max, etc.
```

## Resources

### References

- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting)
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [42 Docs — Push Swap](https://harm-smits.github.io/42docs/projects/push_swap)

### AI Usage

AI assistance (Claude) was used during this project for:

- Understanding how to adapt radix sort to the two-stack constraint
- Explaining bitwise operations and how to isolate individual bits
- Debugging edge cases in the sorting logic for 3–5 element cases
- Clarifying norminette rules (function line count, variable limits)

AI was **not** used to write final code directly. All implementations were written, understood, and tested manually. AI served as a learning and debugging aid throughout the process.
