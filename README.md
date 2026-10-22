*This project has been created as part of the 42 curriculum by nvoronts, vbertych.*

# push_swap

## Description

`push_swap` sorts a list of distinct integers using two stacks and a restricted
set of stack operations. It prints an operation sequence that places the values
in ascending order in stack A, with the smallest value at the top. The project
compares three sorting strategies and includes an adaptive mode that selects a
strategy using the input's initial disorder.

The disorder is the number of out-of-order pairs divided by the number of all
pairs, giving a value from 0 (already sorted) to 1 (reverse sorted). It is
calculated before any sorting operations.

## Instructions

Build with:

```sh
make
```

This creates the `push_swap` executable using `cc -Wall -Wextra -Werror`.
The Makefile also provides `make clean` to remove object files, `make fclean`
to remove object files and the executable, and `make re` to rebuild from
scratch.

Run the program with a list of integers. The first integer is the top of stack
A. Strategy selection is optional; adaptive mode is the default.

```sh
./push_swap 4 67 3 87 23
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Use `--bench` to print the initial disorder, selected strategy, total operation
count, and per-operation counts to standard error. The sorting operations
remain on standard output and can be piped to a compatible checker.

```sh
./push_swap --bench 4 67 3 87 23
```

## Algorithms

All complexity claims below refer to the number of Push_swap operations
generated, as required by the project specification. They are asymptotic upper
bounds, not claims that every input produces the minimum possible sequence.

### Simple: O(n^2)

The simple strategy repeatedly finds the minimum value in stack A, brings it
to the top, and pushes it to stack B. It sorts the small remainder in A, then
moves the saved values back. Finding and moving each minimum takes at most
O(n) stack operations, repeated O(n) times, for an O(n^2) upper bound.

### Medium: O(n sqrt(n))

The medium strategy divides the normalized ranks into ranges whose width is
proportional to sqrt(n). It scans and rotates stack A to extract each range
into B, then returns that range to A in descending maximum order. There are
O(sqrt(n)) ranges; each range costs O(n) to scan and at most O(n) operations
to restore its values, giving an O(n sqrt(n)) upper bound.

### Complex: O(n log(n))

The complex strategy is a least-significant-bit radix sort over normalized
ranks from 0 to n - 1. For each rank bit, it scans A once, pushes zero-bit
values to B, rotates one-bit values in A, and then pushes B back to A. There
are O(log(n)) bits and O(n) operations per bit, giving O(n log(n)).

### Adaptive

Adaptive mode measures disorder before sorting and selects a strategy by these
thresholds:

| Disorder | Strategy | Operation bound |
| --- | --- | --- |
| Less than 0.2 | Simple minimum extraction | O(n^2) |
| 0.2 to less than 0.5 | Medium range chunks | O(n sqrt(n)) |
| 0.5 or greater | Complex radix sort | O(n log(n)) |

The thresholds divide nearly sorted inputs, moderately disordered inputs, and
highly disordered inputs so that each regime uses the strategy whose operation
bound is intended for it. Disorder measurement itself uses pair comparisons
and takes O(n^2) CPU time before any moves; it does not add Push_swap
operations. The two stack buffers use O(n) space. The algorithms use no
additional input-sized storage.

## Contributors

- `vbertych`: initial project structure, argument/configuration handling,
  error handling, program entry point, and core stack operations.
- `nvoronts`: sorting strategies, rank preparation, being late my a month.
Both learners are responsible for understanding and reviewing the complete
project, including the algorithms and their operation bounds.

## Resources

- The `en.subject.pdf` project specification in this repository.

### AI use

AI assistance was used to explain C enum-name conflicts, suggest small
Norminette-oriented refactorings, and help draft and check the Makefile and
this documentation against the project specification.