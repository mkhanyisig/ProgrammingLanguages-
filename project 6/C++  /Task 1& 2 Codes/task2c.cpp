/*
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	C++: Functions and File I/O
*/

#include <stdio.h>
#include <stdarg.h>
 
 
/* demonstrating overloading differences in files  */  
 
float average ( int Count, ... ){
	va_list Numbers;
	va_start(Numbers, Count); 
	int Sum = 0;
	for(int i = 0; i < Count; ++i )
		Sum += va_arg(Numbers, int);
	va_end(Numbers);
	return (Sum/Count);
}

int main(){
      float Average = average(9,88,75,66,44,26,32,12,91,5,3,48,6,3);
      printf("Set of numbers average : %f\n", Average);
      return 0;
}



