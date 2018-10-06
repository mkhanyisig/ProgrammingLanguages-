/**
 *
 *   Mkhanyisi Gamedze
 *  CS333: Programming languages
 *	Linked list C file
 *  project 7:  Part I: Memory Management in C
 * 	21 December 2017 
 */
 

#include<time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(){
	/*
	What is the average time per call to allocate a certain amount of memory?

	Try timing several hundred/thousand calls to make the estimate, and try the 
	experiment with at least three different memory sizes (small, medium, large)
	*/
     
    char *mem_allocation;
    // dynamically  allocated char memory
    double time_spent= 0.0; //
	int size=1000;
	
	
	/*  SMALL */
	int mem_size=20; // allocated memory size 
	for(int i=0;i<size;i++){ // small memory allocation *mem_size=20
		clock_t begin = clock();
			mem_allocation = malloc( mem_size * sizeof(char) );
			free(mem_allocation);
		clock_t end = clock();
		time_spent += (double)(end - begin);
	}
	double avgtime =time_spent/CLOCKS_PER_SEC/size;

	printf("**  small : time spent %f   \n",avgtime );
    
    /*  MEDIUM */
    mem_size=2000000; // allocated memory size 
	time_spent= 0.0;
	for(int i=0;i<size;i++){ // small memory allocation *mem_size=20
		clock_t begin = clock();
			mem_allocation = malloc( mem_size * sizeof(char) );
			free(mem_allocation);
		clock_t end = clock();
		time_spent += (double)(end - begin);
	}
	avgtime =time_spent/CLOCKS_PER_SEC/size;

	printf("**  medium : time spent %f   \n",avgtime );
	
	
	/*  LARGE */
	mem_size=1000000000; // allocated memory size 
	time_spent= 0.0;
	for(int i=0;i<size;i++){ // small memory allocation *mem_size=20
		clock_t begin = clock();
			mem_allocation = malloc( mem_size * sizeof(char) );
			free(mem_allocation);
		clock_t end = clock();
		time_spent += (double)(end - begin);
	}
	avgtime =time_spent/CLOCKS_PER_SEC/size;

	printf("**  large : time spent %f   \n",avgtime );
    
    
    
	/*  Varying size */
	
	time_spent= 0.0;
	for(int i=0;i<size;i++){ // small memory allocation *mem_size=20
		clock_t begin = clock();
			mem_allocation = malloc( 10^(i%6) * sizeof(char) );
			free(mem_allocation);
		clock_t end = clock();
		time_spent += (double)(end - begin);
	}
	avgtime =time_spent/CLOCKS_PER_SEC/size;

	printf("**  varying : time spent %f   \n",avgtime );
    
    
    // test statements
    /*
     if( mem_allocation== NULL ){
        printf("Unable to allocate requested memory\n");
     }
     else
     {
        strcpy( mem_allocation,"mm");
     }
     printf("Dynamically allocated memory content : " \
            "%s\n", mem_allocation );
     free(mem_allocation);
     */
}


