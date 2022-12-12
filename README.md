# push_swap
This project is sorting data on a stack, with a limited set of instructions, using
the lowest possible number of actions. 

## introduction
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
it takes a set of integer values via standard input, 2 stacks, and a set of instructions to manipulate both stacks.
it's writen in C, will calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

## discription
i used radix 

## Rules
* You have 2 stacks named a and b.
* At the beginning:
* The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the
  following operations at your disposal:
* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a.
* Do nothing if b is empty.
* pb (push b): Take the first element at the top of a and put it at the top of b.
* Do nothing if a is empty.
* ra (rotate a): Shift up all elements of stack a by 1.
* The first element becomes the last one.
* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1.
* The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

## checker
this "checker" program Executes the sorting instructions and checks if the values are sorted or not and displas on the standard output "OK\n" or "KO\n"
accordingly
* checker program takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack. If no argument is given, it stops and displays nothing.
* It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
* If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
* In every other case, it must display "KO" followed by a ’\n’ on the standard output.
* In case of error, you must display "Error" followed by a ’\n’ on the standard er- ror. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.


## Expamples for running
$>./push_swap 2 1 3 6 5 8 sa
pb pb
pb sa
pa pa
pa
$>./push_swap 0 one 2 3
Error $>

## Examples for the Checker program
$>./checker 3 2 1 0 rra
pb sa
rra pa
OK
$>./checker 3 2 1 0
sa rra
pb KO
$>./checker 3 2 one 0 Error
$>./checker "" 1 Error
$>


