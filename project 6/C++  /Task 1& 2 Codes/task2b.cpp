/*
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	C++: Functions and File I/O
*/
#include <iostream> 
#include <fstream> // to both read & write to files
using namespace std;


/* demonstrating overloading differences in files  */ 

void ov(){
	cout<<"zero parameter func "<<endl;
}

void ov(int a){
	cout<<"int "<<a<<endl; 
}

void ov(int a,int b){
	cout<<"two ints   : "<<a<<"  "<<b<<endl;
}


int main () {
	
	int x=5,y=10;
	
	ov();
	ov(x);
	ov(x,y);
	
  return 0;  // main function cannot compile without a return statement
}
