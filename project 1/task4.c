/**
		 * CS 333 Programming Languages FA17
		 * Project 1 task 4
		 *
		 * Mkhanyisi Gamedze
		 * 21 Sepetember 2017
*/

		#include <stdio.h>
		#include <stdlib.h>	  
		#include <string.h>
		

		/*   task 4
		 */ 
		 
		struct student {
			// declaring my variables
			int boxnumber;
			char name[10];
			char nationality[18];
			short int year;
		}; 
		 
		 
		int main (int arg, char *argv[]) {
		
			struct student me; 
			
			// declaring my variables
			strcpy(me.name, "Mkhanyisi");
			me.boxnumber=1;
			strcpy(me.nationality,"Swazi");
			me.year=3;
			
			char *str;
			// Set up the structure so it should use an odd number of bytes 
			
			str = (char *) malloc(15);
			
   			strcpy(str, me.name); 
   			printf(" the variable  %s has a byte size %lu  at the location %d , str is @ location %u \n \n ",me.name,sizeof(me.name),*me.name, *str );
   			
   			// loop through the struct,to see how memory is allocated
   			unsigned char *p;
   			p=(unsigned char *)&(me);
   			// loop though struct
   			printf("size of struct : %lu  \n \n \n ", sizeof(me) );
   			for (int i=0;i<sizeof(me);i++){
   				printf(" @location:  %p    , value of ptr  --> %d \n ", p+i, *(p+i));
   			}
  
			
			unsigned char *ptr; 

		  // your stuff here	
		  
		  
					
		  return 0;
		}  