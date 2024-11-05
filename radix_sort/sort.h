#ifndef SORT_H
#define SORT_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
/* given function to print an array of ints */
void print_array(const int *array, size_t size);
/* function to sort array using radix sort */
void radix_sort(int *array, size_t size);
/* helper function to determine max number of digits in array of ints */
int digit_counting(int *array, size_t size);
/* helper function to get the divisor to get specific digit from number */
int get_divisor(int current_digit);
/* helper function to sort & insert value into temp holder by current digit */
void insert_into_holder(int value, int divisor, int *holder, unsigned int i);

#endif
