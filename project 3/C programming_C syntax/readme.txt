Mkhanyisi Gamedze 
CS333 Project 2
26 September 2017

Compiler used: terminal 
macOS Sierra version 10.12.6


# task 1

I created the abstract class cstk.h which had unimplemented methods

# task 2

This task is self explanatory, with multiple comments on my functions for further understanding.
This file implements the methods in the abstract class "cstk.h", and it creates a stack data strcture
using c code, to support the push, pull & pop functions for an array implementation of a stack. 
The display method traverses through the array printing out the stack contents. 

I tried to implement a stack function in my init that would allow it to support more than just an int, 
and this was to be an extension, but with time I could not finish.

# task 3

I ran the test file and my output is shown by the attached image "result" in my Part I folder.  


###########

Extensions

1. I made my stack more robust to handle situations of overflow, by adding necessary if statements that avoid it from overflowing and giving errors. This is added onto my push method. 

2. I added two new functions, isEmpty() and isFull which are functions that check the state of the stack, and these help me avoid errors when adding or popping from stack.


3. 
 


