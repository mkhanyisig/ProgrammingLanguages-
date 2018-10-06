/**
		 * CS 333 Programming Languages FA17
		 * Project 1 task 3
		 *
		 * Mkhanyisi Gamedze
		 * 21 Sepetember 2017
*/

		#include <stdio.h>
		#include <stdlib.h>	  
		#include <string.h>
		

		/*   task3
		 */ 
		int main (int arg, char *argv[]) {
		
		  char *ptr;
		   
		  
		  // memory allocation for loop
		  for (int i=0; ; i++){
		  	ptr=(char *)malloc(20000); // allocate 50 bytes and then assign the  pointer to the memory location
		  	free(ptr);
		  }
		  
		  
		  // your stuff here	
		  
		  
					
		  return 0;
		}  
