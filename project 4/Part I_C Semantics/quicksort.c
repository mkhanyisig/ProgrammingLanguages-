/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 *
 *  Modified by : Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 4: C Semantics
 */

#include <stdio.h>
#include <stdlib.h>

/*
*
Objective : Given an array of random integers, sort the array in a way that the even
numbers apper first and the odd numbers apper later. The even numbers should be sorted 
in descending order and the odd numbers should be sorted in ascending order

I read about a helpful comparator algorithm very helpful toward solving this problem on this site: 
	-->	http://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
*
*/



/* the comparator funciton used in qsort */           
int comparator (const void *p, const void *q) {// comparator takes in two addresses p & q

	// obtain the values at the given addresses
    int left = *(const int *)p;
    int right = *(const int *)q;
 
    // if both values are even, place greater of first two first 
    if (left % 2==0 && right % 2==0)
        return (right-left);
 
    // if both values are odd, place the smaller value first 
    if ( left % 2==1 && right % 2==1 )
        return (left-right);

    // if left term is even, place it first
    if (left % 2==0 )
        return -1;
 
    // if left term is odd, put it first
    return 1;	
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}