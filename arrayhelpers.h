#ifndef _ARRAYHELPERS_H
#define _ARRAYHELPERS_H
#include "arrayhelpers.h"

void int_swap(int *a, int *b);
void array_print (int *array, int length);
void array_sort(int *array, int length);
void array_rotate1(int *array, int length);
void array_rotate(int *array, int length, int k);
void array_reverse(int *array, int length);
int array_search(int *haystack, int  haystack_length, int *needle, int  needle_length);

#endif
