/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 3: C Syntax
*    1 October 2017
*
* 	
*/


extern int CSTK_MAX;


// This defines the type of objects entered into the stack.
typedef int stackElementT;



// type for a stack, i.e., it is a type that holds the information necessary to keep track of a stack
typedef struct stack {
		stackElementT *Contents; //  a pointer `contents' to a dynamically-allocated array,(used to hold the contents of the stack)
		int* stack;
		int top;  // holds index of the top of the stack
		int size;
	} Stack;
	
// 	creates a stack with the size specified by the int value
/*
*		 A new stack variable is initialized.  This initialized stack is made empty. 
* 		 
*/
Stack* stk_create( int max_size);

// frees all memory associated with the stack
void stk_destroy (Stack *StackP);


// 		adds a new value to the top of the stack
void stk_push(Stack	*stackP, int value);

// 	removes a value from the top of the stack
int stk_pop(Stack	*stackP);

// prints out the list in the reverse order if the int value is 1, otherwise, prints out in the original order
void stk_display(Stack* stk, int val);

int isEmpty(Stack	*stackP);

int isFull(Stack	*stackP);
