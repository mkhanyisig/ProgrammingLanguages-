/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 3: C Syntax
*    1 October 2017
*
* 	
*/


#include <stdio.h>
#include <stdlib.h>  /* for dynamic allocation */
#include "cstk.h"       

int CSTK_MAX=50;


Stack* stk_create(int max_size){
	stackElementT *Contents; // create new pointer for contents
	
	// allocate new array to hold elements, and allocate it the necessary memory
	/* malloc allocates the requested memory and returns a pointer to it */
	Contents = (stackElementT *)malloc(sizeof(stackElementT) * max_size);
	Stack *stackP=malloc(sizeof(Stack));  // create new stack
	
	
	
	
	// error check, incase not enough memory available for new allocation
	if (Contents == NULL) {
    	printf("Insufficient memory to initialize stack.\n");
    	exit(1);  /* Exit, returning error code. */
    }
    
    // intialise stack variables
    stackP->Contents = Contents;
    stackP->stack = malloc(sizeof(int)*max_size); 
  	stackP->size = max_size;
  	stackP->top = -1;  // implies empty
  	
  	return stackP;
}

void stk_destroy (Stack *stackP){
	// delete arrays
	free(stackP->Contents);
	free(stackP->stack);
	
	/* re-intialize variables	*/
	
    stackP->stack = NULL; // same as above
  	stackP->top = -1;  // implies empty
}

void stk_push(Stack *stackP, stackElementT value){

	// first check whether it is full or not
	if (isFull(stackP)==1){
		printf("stack is full, can't push \n ");
		exit(1); // error
	}
	 // if this condition is false, then push element
	stackP->stack[++stackP->top] = value;
}


// pop and return removed element
stackElementT StackPop(Stack *stackP)
{
  if (isEmpty(stackP)==1) {
    printf("stack is empy : error \n ");
    exit(1);  // error
  }

  return stackP->stack[stackP->top--]; // decrease the top value for the stack and return popped value
}


void stk_display(Stack* stk, int val){
	int b=stk->top;
	if(val == 1){
		//printf("reverse order");
		for(int i=b ; i>=0 ; i--){
			printf(" %d",stk->stack[i]);
		
		}
		printf("\n");
		
	}
	else{
		//printf("proper order");
		for(int i=b ; i>=0 ; i--){
			printf(" %d",stk->stack[b-i]);
		
		}
		printf("\n");
		
	}
}

// new stack methods

int isEmpty(Stack	*stackP){ // member function to check if stack is empty
	// if empty return 1, if not, return -1
	if (stackP->top == -1){
		printf("stack i empty \n ");
		return 1;
	}
	else{
		// stack is not empty
		return -1;
	}
	

}

int isFull(Stack	*stackP){ // member function to check if stack is empty
	// if full return 1, if not, return -1
	if (stackP->top >= stackP->size-1){
		printf("stack i empty \n ");
		return 1;
	}
	else{
		// stack is not empty
		return -1;
	}
	

}














