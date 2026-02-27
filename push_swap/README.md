#
**PUSH_SWAP**
#

push_swap is an algorithmic project from 42 School.
The objective is to sort a stack of integers using the minimum number of operations, with only two stacks and a restricted set of instructions.

##
This project focuses on:
##

1. Sorting algorithms
2. Optimization
3. Data structures (linked lists)
4. Algorithmic complexity

##
Objective:
##

Sort a list of integers given as arguments using only the allowed operations.
The program must print on the standard output the sequence of operations required to sort the stack in ascending order.

##
Allowed operations:
##

###
Swap (ft_method_swap.c)
###

sa : swap the first two elements of stack A
sb : swap the first two elements of stack B
ss : execute sa and sb at the same time

###
Push (ft_method_push.c)
###

pa : push the top element from stack B to stack A
pb : push the top element from stack A to stack B

###
Rotate (ft_method_rotate.c)
###

ra : shift up all elements of stack A
rb : shift up all elements of stack B
rr : execute ra and rb at the same time

###
Reverse Rotate (ft_method_reverse_rotate.c)
###

rra : shift down all elements of stack A
rrb : shift down all elements of stack B
rrr : execute rra and rrb at the same time

###

##
Compilation:
##

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove the executable:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

##
Usage
##

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the sequence of operations needed to sort the numbers.

##
Turk Algorithm Principle:
##

* Index assignment
* Position calculation
* Target determination
* Cost calculation
* Optimized rotations (Turk algorithm approach)
* Error management

##
The program handles:
##

* Invalid characters
* Non-numeric inputs
* Integer overflow
* Duplicate numbers
* Empty arguments
* In case of error, the program prints: Error

##
Performance objectives:
##

| Number of elements | Number of operations |
| ------------------ | -------------------- |
| 3                  | ≤ 3                  |
| 5                  | ≤ 12                 |
| 100                | ≤ 700                |
| 500                | ≤ 5500               |

##
**Run/Tests**
##

Simple example:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```
Result: 9

Using a checker:

```bash
./push_swap $ARG | ./checker $ARG
```
Result: OK

PS: The libft is already included in the Makefile and will be compiled automatically.
To verify correct behavior, you must add `checker_linux` + rights ```bash chmod +x checker_linux``` , to compare the results properly.
