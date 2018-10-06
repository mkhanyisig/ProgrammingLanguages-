/**
		 * CS 333 Programming Languages FA17
		 * Project 1 task 2
		 *
		 * Mkhanyisi Gamedze
		 * 21 Sepetember 2017
*/

		#include <stdio.h>
		#include <stdlib.h>	  
		#include <string.h>
		

		/*   task2
		 */ 
		int main (int arg, char *argv[]) {
			// declaring my variables
			char name[20]="mkhanyisi gamedze";
			char gender='M'; //F or M
			char bday[10]="19960220"; //YYYYMMDD
			char address[50]="6170 Mayflower";
			char nationality[15]="Swazi";
			int year=3;
			unsigned char *ptr; 
			ptr=(unsigned char *)&(ptr);  // Give ptr the address of itself
			
			//  a for loop that prints out and accesses memory in sequence using the unsigned char * from index zero onwards 
			for (int i=0; ;i++){
				printf(" @location:  %p    , value of ptr  --> %d  total memory accessed=%u \n ", ptr+i, *(ptr+i), i);
			}
		  
		  
		  // your stuff here	
		  
		  
					
		  return 0;
		}  