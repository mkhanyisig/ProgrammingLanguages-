/**
		 * CS 333 Programming Languages FA17
		 * Project 1  task 1
		 *
		 * Mkhanyisi Gamedze
		 * 21 Sepetember 2017
*/

		#include <stdio.h>
		#include <stdlib.h>	  
		#include <string.h>

		
		/* Assigns variables of basic types, and then loops through their pointers
		 */ 
		int main (int arg, char *argv[]) {
			// task1
			printf("***    Task 1 Mkhanyisi CS333   *** \n \n \n \n");
			
			unsigned char *ptr;  // declare ptr to be used on probing around in memory
			
			// char type
			printf("  ** looking into char \n ");
			char character = 'a';
			ptr=(unsigned char *)&(character);
			for (int j = 0; j < sizeof(char); j++) {	
 				printf(" @location:  %p    , value of ptr  --> %d \n ", ptr+j, *(ptr+j));
 			}
			
			// float type
			printf(" \n \n  ** looking into float \n ");
			float accountBalance=100000.00;
			ptr=(unsigned char *)&(accountBalance);
			for (int j = 0; j < sizeof(float); j++) {	
 				printf(" @location:  %p    , value of ptr  --> %d \n ", ptr+j, *(ptr+j));
 			}
			
			// Size qualifiers(long/short) alters the size of a basic type
			printf("\n \n  ** looking into a long  \n ");
			long l=100000; //The size of double is 8 bytes. However, when long keyword is used, that variable becomes 10 bytes.
			ptr=(unsigned char *)&(accountBalance);
			for (int j = 0; j < sizeof(long); j++) {	
 				printf(" @location:  %p    , value of ptr  --> %d \n ", ptr+j, *(ptr+j));
 			}
			
			
			// examining short
			printf(" \n \n ** looking into a short \n ");
			short s=12; //  short which can be used if you previously know the value of a variable will always be a small number, thus requiring less bytes
			ptr=(unsigned char *)&(s);
			for (int j =0; j < sizeof(short); j++) {
				printf(" @location:  %p    , value of ptr  --> %d \n", ptr+j, *(ptr+j));
			}
			
			
			// integer
			printf(" \n \n \n  ** looking into  an integer    #####   [little Endian]\n ");
			int positiveInteger=100; 
			ptr=(unsigned char *)&(positiveInteger);
			for (int j =0; j < sizeof(int); j++) {
				printf(" @location:  %p    , value of ptr  --> %d \n", ptr+j, *(ptr+j));
			}
			
			// signed integer
			printf("\n \n  ** looking into signed integer \n ");
			signed int unsignedInteger=-200;
			ptr=(unsigned char *)&(unsignedInteger);
			for (int j =0; j < sizeof(int); j++) {
				printf(" @location:  %p    , value of ptr  --> %d \n", ptr+j, *(ptr+j));
			}
			
			
			
			printf("\n \n ********* Thank you, first task done   **********\n \n ");
			
			
			
			
			
			
		  // your stuff here	
					
		  return 0;
		}  
