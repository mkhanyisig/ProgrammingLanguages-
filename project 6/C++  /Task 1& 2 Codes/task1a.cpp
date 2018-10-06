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


/* Demonstrating how to open file and write into it in c++  */ 
int main () {
  ofstream myfile;
  myfile.open ("f1.txt"); // creates new file
  myfile << "This is a demo\n";
  cout<<"done writing into file "<<endl;
  
  myfile.close();
  
  return 0;
}