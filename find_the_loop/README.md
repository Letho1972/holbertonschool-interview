# Find the Loop

Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
No standard library functions allowed. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called lists.h
Don’t forget to push your header file
All your header files should be include guarded
Please use this lists.h:

Write a function that finds the loop in a linked list.

Prototype: listint_t *find_listint_loop(listint_t*head);
Returns: The address of the node where the loop starts, or NULL if there is no loop
You are not allowed to use malloc, free or arrays
You can only declare a maximum of two variables in your function
Note: In order to compile the main file, you are provided with this static library. This library won’t be used during the correction; Its only purpose is for testing.
