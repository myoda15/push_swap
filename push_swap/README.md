# Push Swap

*This project has been created as part of the 42 curriculum by mande-so.*

## Description

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves possible. The goal is to implement an efficient sorting algorithm that works within the constraints of two stacks (stack A and stack B) and a specific set of allowed operations.

The project consists of two programs:
-	**push_swap**: Takes a list of integers as arguments and outputs the sequence of operations needed to sort them
-	**checker** (bonus): Reads operations from stdin and verifies if they correctly sort the given integers

The challenge lies in finding an algorithm that minimizes the number of operations while maintaining efficiency across different input sizes (from 3 to 500+ numbers).

## Instructions

### Compilation

The project uses a Makefile with the following rules:

```bash
make        # Compiles the push_swap program
make bonus  # Compiles the checker program
make clean  # Removes object files
make fclean # Removes object files and executables
make re     # Recompiles everything from scratch
```

### Usage

**Push Swap:**
```bash
./push_swap 3 2 1 5 4
```

The program outputs the operations needed to sort the numbers:
```
pb
pb
sa
pa
pa
```

**Checker (bonus):**
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

The checker reads the operations from stdin and outputs:
- `OK` if the stack is sorted correctly
- `KO` if the stack is not sorted
- `Error` if invalid operations or arguments are provided

### Available Operations

-	`sa`: swap the first two elements of stack A
-	`sb`: swap the first two elements of stack B
-	`ss`: sa and sb at the same time
-	`pa`: push the first element of B to A
-	`pb`: push the first element of A to B
-	`ra`: rotate stack A (shift up all elements by 1)
-	`rb`: rotate stack B
-	`rr`: ra and rb at the same time
-	`rra`: reverse rotate stack A (shift down all elements by 1)
-	`rrb`: reverse rotate stack B
-	`rrr`: rra and rrb at the same time

### Performance Benchmarks

The project is graded based on the number of operations used:

**For 100 numbers:**
-	5 points: less than 700 operations
-	4 points: less than 900 operations
-	3 points: less than 1100 operations

**For 500 numbers:**
-	5 points: less than 5500 operations
-	4 points: less than 7000 operations
-	3 points: less than 8500 operations

**Current implementation:**
-	100 numbers: ~1084 operations (3/5 points)
-	500 numbers: ~6784 operations (3/5 points)

## Project Structure

```
push_swap/
├── Makefile
├── push_swap.h
├── libft/					# Custom C library
│	└── ...
└── srcs/
	├── main.c				# Main program entry point
	├── error.c				# Error handling
	├── parsing.c			# Input validation
	├── init.c				# Stack initialization
	├── operations/			# Stack operations (sa, pa, ra, etc.)
	│	├── swap.c
	│	├── push.c
	│	├── rotate.c
	│	└── reverse_rotate.c
	├── algorithm/			# Sorting algorithms
	│	├── sort_small.c	# For 2-3 numbers
	│	├── sort_medium.c	# For 4-5 numbers
	│	└── sort_large.c	# For 100+ numbers (radix sort)
	├── utils/				# Helper functions
	│	├── stack_utils.c
	│	└── utils.c
	└── bonus/				# Checker program
		├── checker.c
		├── checker_ops.c
		├── checker_utils.c
		└── get_next_line.c
```

## Algorithm Overview

The implementation uses different strategies based on input size:

-	**2-3 numbers**: Hardcoded optimal solutions
-	**4-5 numbers**: Move smallest elements to stack B, sort remaining, push back
-	**100+ numbers**: Radix sort algorithm using binary representation of indexed values

The radix sort implementation:
1.	Assigns an index to each number based on its relative position
2.	Sorts by processing each bit of the index from LSB to MSB
3.	For each bit, pushes numbers with bit=0 to stack B, rotates numbers with bit=1
4.	Pushes everything back from B to A after each bit iteration

## Resources

### Classic References
-	[Sorting Algorithms Visualization](https://visualgo.net/en/sorting)
-	[Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Helpful tool to visualize the sorting process
-	[42 Docs - Push Swap](https://harm-smits.github.io/42docs/projects/push_swap)
-	[Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)

### AI Usage
AI assistance (GitHub Copilot) was used during this project for:

**Tasks where AI helped:**
-	Understanding the radix sort algorithm and how to adapt it to the two-stack constraint
-	Debugging norminette compliance issues (function length, variable declarations)
-	Explaining pointer mechanics and linked list operations
-	Code structure organization and function splitting to meet 42 norm requirements
-	Writing test cases and understanding edge cases (overflow, duplicates, invalid input)

**Parts implemented with AI guidance:**
-	Initial project structure and Makefile setup
-	Error handling implementation (parsing, validation)
-	Radix sort algorithm adaptation for the push_swap constraints
-	Bonus checker program with get_next_line integration

**Parts implemented independently:**
-	Stack operations logic (all 11 operations)
-	Small number sorting algorithms (2-5 elements)
-	Algorithm selection based on input size
-	Manual testing and debugging

The AI was particularly useful for understanding complex concepts and catching edge cases, but all final code decisions and implementations were reviewed and understood before integration. The learning process focused on understanding why certain approaches work rather than blindly copying solutions.

## Testing

Generate random tests:
```bash
# Test with 100 numbers
ARG=$(python3 -c "import random; nums = list(range(1, 101)); random.shuffle(nums); print(' '.join(map(str, nums)))")
eval "./push_swap $ARG" | eval "./checker $ARG"

# Test with 500 numbers
ARG=$(python3 -c "import random; nums = list(range(1, 501)); random.shuffle(nums); print(' '.join(map(str, nums)))")
eval "./push_swap $ARG" | eval "./checker $ARG"

# Count operations
ARG=$(python3 -c "import random; nums = list(range(1, 101)); random.shuffle(nums); print(' '.join(map(str, nums)))")
eval "./push_swap $ARG" | wc -l
```

Error handling tests:
```bash
./push_swap "a" 1 2        # Should output: Error
./push_swap 1 2 2          # Should output: Error (duplicate)
./push_swap 2147483648     # Should output: Error (overflow)
./push_swap                # Should output nothing
./push_swap 42             # Should output nothing (already sorted)
```

## Author

Project completed by **mande-so** at 42 Lisboa.
