/**
		 * CS 333 Programming Languages FA17
		 * Project 1 task 5
		 *
		 * Mkhanyisi Gamedze
		 * 21 Sepetember 2017
*/

		#include <stdio.h>
		#include <stdlib.h>	  
		#include <string.h>
		 
		int main (int arg, char *argv[]) {
		
			char var[5]="cat"; 
			int i = 1;

			strcpy(var, "college");  // override with 7 character string instead of expected 5

			if (i==1) {
				printf("safe");
			} 
			else{
				printf("something went wrong man");
			}
			// your stuff here	
			return 0;
		}  





	