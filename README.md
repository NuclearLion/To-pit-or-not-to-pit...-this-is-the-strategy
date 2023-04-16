Copyright Dan-Dominic Staicu 311CA (dando.ds11@gmail.com) 2023
**Nume: Dan-Dominic Staicu**
**Grupă: 311CAb**

## To pit or not to pit... this is the strategy - Homework 1

>First Law of Holes: The first step in getting out of the hole your dug for yourself is to stop digging.

### Description:

* It's purpose is to simulate Ferrari's system of operating with sensort data
 (but probably mine's better)

* It reads data from a binary file and saves it to an array in order to do the
 operations easier; it sorts everything in the end according to the sensors'
 type using C's qsort from <stdlib.h>; the binary file is given as a parameter
 of main;

* It reads commands from stdin and interprets them in oder to offer output at
 stdout; it executes them until "exit" is inputed;

* It prints the data of any sensor at a given index, according to it's type;

* It analysis the data of these sensors, by appling given operations and
 printing the output; they are kept in an array of pointers to functions,
 because those are static functions that can not be called outside the .c
 file where they are written;

* It clears from memory all the sensors which have wrong values and using
 using realloc uses less memory for the given array; it frees the fields of the
 removed sensors before reallocing so no leaks are possible; 

* When exit is inputed, all the alloc'd memory is free'd;

> Hinds' Law Of Computer Programming:
> "If a program is useless, it will have to be documented."