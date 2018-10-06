/*
	Bruce Maxwell
	Fall 2012
	CS 333

	Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// function that prints an integer
void printInt(void *i) {
	int *a = (int *)i;

	printf("value: %d\n", *a);
}

// print character inputs
void printChar(void *i) {
	char *a = (char *)i;

	printf("value: %c\n", *a);
}

// function that squares an integer
void squareInt(void *i) {
	int *a = (int *)i;

	*a = *a * *a;
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
	int *a = (int *)i;
	int *b = (int *)j;
	//printf("\nresult  %d",*a == *b);
	return(*a == *b);
}

// function that compares two characters and returns 1 if they are equal
int compChar(void *i, void *j) {
	char *a = (char *)i;
	char *b = (char *)j;
	
	return(*a == *b);
}


// test function for the various linked list functions
int main(int argc, char *argv[]) {
	LinkedList *l;
	int *a;
	int *target;
	int i;

	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<20;i+=2) {
		a = malloc(sizeof(int));
		*a = i;

		ll_push(l, a);
	}

	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printInt);

	ll_map(l, squareInt);

	printf("\nAfter squaring\n");
	ll_map(l, printInt);

	// testing removing data
	target = malloc(sizeof(int));

	*target = 16;
	//printf("remove: %d",*target);
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	*target = 11;
	//printf("remove: %d",*target);
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	printf("\nAfter removals\n");
	ll_map(l, printInt);
	
	printf("\nAppending\n");
	// testing appending data
	ll_append(l, target);

	printf("\nAfter append\n");
	ll_map(l, printInt);

	// test clearing
	ll_clear(l, free);

	printf("\nAfter clear\n");
	ll_map(l, printInt);

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		a = malloc(sizeof(int));
		*a = i;
		ll_append(l, a);
	}

	printf("\nAfter appending\n");
	ll_map(l, printInt);

	a = ll_pop(l);
	printf("\npopped: %d\n", *a);
	free(a);

	a = ll_pop(l);
	printf("popped: %d\n", *a);
	free(a);

	printf("\nAfter popping\n");
	ll_map(l, printInt);

	printf("\nList size: %d\n", ll_size(l) );
	
	
	/* second data type input extension of linked list  */
	printf("\n********************************* Second data type:Char \n");
	char name[12]="StudyTonight"; 
	char *b; 	
	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<12;i++) {
		b = malloc(sizeof(char));
		*b = name[i];
		ll_push(l, b);
	}
	
	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printChar);
	printf("\nList size: %d\n", ll_size(l) );
	
	*target = 'S';
	//printf("remove: %d",*target);
	b = ll_remove(l, target, compInt);
	if(b != NULL)
		printf("\nremoved: %c\n", *b);
	else
		printf("\nNo instance of %c\n", *target);
		
	*target = 'T';
	//printf("remove: %d",*target);
	b = ll_remove(l, target, compInt);
	if(b != NULL)
		printf("\nremoved: %c\n", *b);
	else
		printf("\nNo instance of %c\n", *target);
		
	printf("After removing T&S\n");
	ll_map(l, printChar);
	printf("\nList size: %d\n", ll_size(l) );
	
	char nhlo[9]="Nhlonipho"; 
	// testing appending data
	for(i=0;i<9;i++){
		b = malloc(sizeof(char));
		*b =nhlo[i];
		//printf("\nval :%c",nhlo[i]);
		ll_append(l, b);
	}
	
	printf("\nAfter appending\n");
	ll_map(l, printChar);
	printf("\nList size: %d\n", ll_size(l) );
	
	
	b = ll_pop(l);
	printf("\npopped: %c\n", *b);
	free(b);

	b = ll_pop(l);
	printf("popped: %c\n", *b);
	free(b);
	
	 b = ll_pop(l);
	printf("popped: %c\n", *b);
	free(b);
	
	b = ll_pop(l);
	printf("popped: %c\n", *b);
	free(b);
	
	printf("\nList size: %d\n", ll_size(l) );
	return(0);
}