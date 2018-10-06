/*
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	C++: Functions and File I/O
*/

// basic file operations
#include <iostream> 
#include <fstream> // to both read & write to files
using namespace std;

int retInt(){
	cout<<"Int return statement"<<endl;
	return 1;
}
void retVoid(){
	cout<<"void return statement"<<endl;
}

/* demonstrating how functions can have void type  */ 
int main () {
	
	retInt();
	retVoid();
	
	
  return 0;  // main function cannot compile without a return statement
}
