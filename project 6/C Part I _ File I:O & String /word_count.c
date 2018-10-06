/**
 *
 *   Mkhanyisi Gamedze
 *  CS333: Programming languages
  *	Linked list h file
 *  project 6:  File I/O and String in C
 *  6 November 2017 
 *  Get a filename from standard in, read the file, and add word into linked list
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "linkedlist.h"
#include<string.h>


/* Map functions for llmap */
void mapNode(Node *n) { // print node data value & frequency
	printf("val: %s   freq: %d \n", n->data, n->count);
}


void mapArray(pair a[],Node *p, int sz, int i) {// Update pair array with Linked list values
	a[i].freq=p->count;
	strcpy(a[i].word, p->data);
	printf("\n               after   d: %s   c:%d\n",a[i].word,a[i].freq);			
}


void printChar(void *i) {// print character input
	char *a = (char *)i;
	printf("value: %c\n", *a);
}

/* comparator function for my qsort */
int comparator(const void *p1, const void *p2){
    int m = ((pair *)p1)->freq;
	int n = ((pair *)p2)->freq; 
    return (n-m);
}

int main() {
	// fields
	int c;
	FILE *fp;
	char fname[50],str[25],str_arr[150][25];
	int wc=0;
	LinkedList *l;
	Node *ptr;
	
	// create a list
	l = ll_create();
	
	// open the file user wants to use
	printf("\nEnter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	
	if(fp==NULL){// error handling 
		// alert about error
		printf("\n\nError 404: File not found \n\nGoodbye...\n");
	}
	else{
		int j=0;
		while (fscanf(fp, "%s", str_arr[j])==1){ // while true
		
			// convert all characters to lowercase
			for (int i = 0; str_arr[j][i] != '\0'; i++){ // whilst not end of string, change char to lowercase
			    str_arr[j][i] = (char)tolower(str_arr[j][i]);
    		}
    		// get rid of punctuation
    		for (int i = 0; str_arr[j][i] != '\0'; i++){ 
			    if(ispunct(str_arr[j][i])!=0){
			    	str_arr[j][i] = '\0';
			    }
    		}
    		printf("->adding: %s \n",str_arr[j]);
    		// add word to linked list
    		ll_add_word(l,str_arr[wc]);
    		wc+=1;
    		j+=1;
		} 			
	}
	printf("\n \n ****   Linked list Quality check   ******");
	ll_mapNode(l, mapNode);
	printf("\n ****   DONE   ******\n\n\n");
	/*  Done with first part, now use list to sort array and print out elements in ascending order */
	
	
	
	//------------------------------- Sorting ---------------------------------------//
	pair list[l->size];
	
	// give struct frequency values a default -ve frequency, this is helpful in my mapArray map-function @ the top
	for(int i=0;i<(l->size);i++){
		list[i].freq=(-1*i);
	}
	
	ll_mapArray(l,mapArray, list, l->size);
	
	// struct quality check
	printf("\n\n//--------------------------------//\nStruct quality check : The words in your Linked List\n");
	printf("\n*freq       *word");
	for(int i=0;i<(l->size);i++){
		printf("\n%d        %s\n",list[i].freq,list[i].word);
	}
	printf("\n//--------------------------------//\n");
	
	qsort (list, l->size, sizeof(pair), comparator); 
	
	// print out top 20
	printf("\n\n\n//************************************//\nWord count : Top 20 words\n");
	for(int i=0;i<(20);i++){
		printf("\n%d        %s\n",list[i].freq,list[i].word);
	}
	printf("\n//****************************************//\n");
	
	
	fclose(fp);  // close file once done
	
	return 0; 
}