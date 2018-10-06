/**
 *
 *   Mkhanyisi Gamedze
 *  CS333: Programming languages
  *	Linked list header file
 *  project 6:  File I/O and String in C
 * 6 November 2017 
 */
 
#include <stdio.h>
#include <stdlib.h>


/* 	Declare structs to be used for LinkedList	*/

typedef struct{ // Node struct
	
	void *previous;  
	void *next;
	int count; 
	void *data;  // void pointer can be used to point to any data type, so this linked list can hold any type value for data
} Node ;

typedef struct {
	Node *head;
	Node *tail;
	int size;
} LinkedList;

	
typedef struct{
	char word[100];
	int freq;
}pair;


LinkedList *ll_create(); //creates a new LinkedList struct, initializes it, and returns it.
void ll_print(LinkedList *l);  // print linked list
void ll_add_word(LinkedList *l, void *d); // checks if list contains word, if true just increase frequency, else just push new value
void ll_push(LinkedList *l, void *data); // adds a node to the front of the list, storing the given data in the node.
void *ll_pop(LinkedList *l); // removes the node at the front of the list and returns the associated data.
void ll_append(LinkedList *l, void *data); // adds a node to the end of the list, storing the given data in the node.
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)); // removes the first node in the list whose data matches target given the comparison function. The function returns the pointer to the data.
int ll_size(LinkedList *l); // returns the size of the list.
void ll_clear(LinkedList *l, void (*freefunc)(void *)); // removes all of the nodes from the list, freeing the associated data using the given function.
void ll_map(LinkedList *l, void (*mapfunc)(void *));
void ll_mapNode(LinkedList *l, void (*mapfunc)(Node *));
void ll_mapArray(LinkedList *l, void (*mapfunc)(pair a[],Node *p, int sz, int z ), pair a[], int arr_size);