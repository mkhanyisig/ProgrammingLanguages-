/**
 *
 *   Mkhanyisi Gamedze
 *  CS333: Programming languages
 *	Linked list C file
 *  project 6:  File I/O and String in C
 * 	6 November 2017 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include<string.h>



LinkedList *ll_create(){  // creates a new LinkedList struct, initializes it, and returns it.	
	// create empty Linkedlist 
	LinkedList *ll;
	 
	// point to LinkedList struct
	ll=(LinkedList *)malloc( sizeof(LinkedList)); 
	
	ll->head=NULL;
	ll->tail=NULL;
	ll->size=0;
	
	return ll;
}

void ll_add_word(LinkedList *l, void *d){ // checks if list contains word, if true just increase frequency, else just push new value
	Node *ptr;
	
	if(l->head==NULL){ // empty LL, just push new node with frequency 0
		ll_push(l, d);
	}
	else{
		int check=0; // int value acts as boolean to check
		ptr=l->head;
		while(ptr->next!=NULL){
			if(strcmp(ptr->data,d)== 0){
				//printf("\nmatch : ptr->data  : %s   d : %s\n",ptr->data,d);
				ptr->count+=1;
				check=1;
				break; // value in the list, so break
			} 
			ptr=ptr->next;
		} 
		if(check==1){printf(" exists -> increase frequency\n");} // do nothing, count already increased
		else{ // push the term into the list
			ll_push(l, d);
		}
	}
}


void ll_push(LinkedList *l, void *d){ // adds a node to the front of the list, storing the given data in the node.
	if(l->size==0){// empty linked list, create root and add it to head
		// root node: unchanging first node
		printf("\n**push into empty list \n");
		Node *root; 

		// root points to a node struct
		root = (Node *) malloc( sizeof(Node) ); 

		// set default values to NULL
		root->next = NULL;  
		root->previous=NULL;
		root->count=1; // word has occured once
		root->data=d;
		
		l->tail=root;
		l->head=root;	
		l->size+=1;
	}
	else if(l->size==1){
		// new temp node
		Node *temp; 
		
		printf("\n##push into size 1 list \n");
		// root points to a node struct
		temp = (Node *) malloc( sizeof(Node) ); 
		
		
		// Set values
		temp->data=d;
		l->head->previous=temp; // previous node to head is  the new temp node
		temp->next=l->head; // tail previous ptr is the head node
		temp->previous=NULL;
		temp->count=1;
		l->head=temp;
		
		l->size+=1;
				
	}
	else{
		printf("\n	General push \n");
		// new head temp node
		Node *temp; 
		Node *inst; 
		
		// root points to a node struct
		temp = (Node *) malloc( sizeof(Node) ); 
		
		// Set values
		inst=l->head;
		inst->previous=temp; // head node previous Node set to new Node 
		temp->next=l->head; // head to  previous 
		temp->previous=NULL;
		temp->count=1;
		l->head=temp; // new head
		temp->data=d;
		l->size+=1;
	}
	
}



void *ll_pop(LinkedList *l){ // remove head
	if(l->size==0){// empty linked list, create root and add it to head
		printf("\nYou cant pop an empty linkedlist\n");
		return NULL;
	}
	else if(l->size==1){
		// new head temp node
		Node *temp;  
		temp=l->head;
		// Free momory & Set values
		// free(l->head); // free head node, since there is no garbage collection in C /* Deallocate allocated memory */
		l->head=NULL; // list is now empty
		l->size-=1;
		return temp;
	}
	else{
		// return node
		Node *ret;
		// new temporary node
		Node *temp;  
		// Free momory & Set values
		temp=l->head->next; // previous node to old tail is  the new tail value
		//l->tail->previous->previous=temp->previous; // connect temp to old previous node
		ret=l->head;
		
		temp->previous=NULL; // break off connection to head
		 
		l->head=temp;
		l->size-=1;
		return ret->data;
	}
}

void ll_append(LinkedList *l, void *d){// adds a node to the end of the list, storing the given data in the node.
	
	//printf("\ninitialized, size=%d",l->size);
	
	if(l->size==0){// empty linked list, create root and add it to head
		// root node: unchanging first node
		Node *root; 

		// root points to a node struct
		root =(Node *) malloc( sizeof(Node) ); 
		// set default values to NULL
		root->next = NULL;  
		root->previous=NULL;
		root->data=d;
		l->head=root;
		l->tail=root;	
		l->size+=1;
	}
	else if(l->size==1){
		// new tail node
		Node *tl; 
		Node *tup; 
		
		// root points to a node struct
		tl = (Node *) malloc( sizeof(Node) ); 
		
		// Set values
		
		tup=l->tail;
		tup->next=tl;  // next node to head is  the new tail
		tl->previous=l->tail; // tail previous ptr is the head node
		l->tail=tl; // new tail
		
		tl->data=d;
		l->size+=1;
				
	}
	else {
	
		// new tail node
		Node *tl; 
		Node *tup; 
		
		// root points to a node struct
		tl = (Node *) malloc( sizeof(Node) ); 
		// Set values
		tl->data=d;
		tl->next=NULL;
		l->tail->next=tl;
		tl->previous=l->tail;
		
		l->tail=tl; // new tail
		
		l->size+=1;

	
	}
	
}


void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){  
	/*   removes the first node in the list whose data matches target given the comparison 
	 *	 function. The function returns the pointer to the data. */
	 
	 Node *ptr;
	 ptr=l->head;
	 Node *t=NULL;
	 
	 
	 int stop=0;
	
	 
	 while(ptr!=NULL){
	 	
	 	//printf("\nvalue %d",ptr->data);
	 	if(compfunc(ptr->data,target)==1){
	 		t=ptr;
	 		
	 		// remove the value
	 		if(ptr==l->head){
	 			printf("\n remove Header");
	 			l->head=ptr->next;
	 			l->head->previous=NULL;
	 			// free memory
	 			
	 			l->size-=1;
	 		}
	 		
	 		else if(ptr==l->tail){
	 			printf("\n remove tail");
	 			l->tail=ptr->previous;
	 			l->tail->next=NULL;
	 			l->size-=1;
	 		}
	 		
	 		else{
	 			printf("\n=>remove none header");
	 			Node *tup,*tdown;
	 			tup=ptr->previous;
	 			tdown=ptr->next;
	 			tup->next=ptr->next;
	 			tdown->previous=ptr->previous;
	 			// free memory for ptr	
	 			
	 			l->size-=1;
	 		}
	 	
	 		break; // value found
	 	}
	 	ptr=ptr->next; // point to next value
	 }
	 return t;
	 
}


int ll_size(LinkedList *l){ //  returns the size of the list.
	return l->size;
}


void ll_clear(LinkedList *l, void (*freefunc)(void *)){
	/*
	*	removes all of the nodes from the list, freeing the associated data using the
	*	 given function.
	*/
	
	Node *ptr;
	Node *temp;
	ptr=l->head;
	
	while(ptr!=NULL){
		temp=ptr;
		ptr=ptr->next;
		// free node memory
		freefunc(temp);
	}
	
	l->head=NULL;
	l->tail=NULL;
	l->size=0;
	
}


void ll_map(LinkedList *l, void (*mapfunc)(void *)){
	// traverses the list and applies the given function to the data at each node.
	Node *ptr;
	ptr=l->head;
	
	while(ptr!=NULL){
		// map data to each node
		mapfunc(ptr->data);
		ptr=ptr->next;
	}

}

void ll_mapNode(LinkedList *l, void (*mapfunc)(Node *)){
	// traverses the list and applies the given function to the data at each node.
	Node *ptr;
	ptr=l->head;
	printf("\nThe words in your list of size %d>\n\n",l->size);
	int c=0;
	while(ptr!=NULL){
		// map data to each node
		//printf("c %d  data %s\n",c,ptr->data);
		mapfunc(ptr);
		ptr=ptr->next;
		c=1+c;
	}

}

void ll_mapArray(LinkedList *l, void (*mapfunc)(pair a[],Node *p, int sz, int z ), pair a[], int arr_size){
	// traverses the list and applies the given function to the data at each node.
	Node *ptr;
	ptr=l->head;
	printf("\nThe words in your list of size %d\n",l->size);
	int c=0;
	
	while(ptr!=NULL){
		// map data to each node
		//printf("c %d  data %s\n",c,ptr->data);
		mapfunc(a,ptr, arr_size,c);
		ptr=ptr->next;
		c=1+c;
	}

}


