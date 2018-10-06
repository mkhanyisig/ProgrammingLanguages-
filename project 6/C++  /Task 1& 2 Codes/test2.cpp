// basic file operations
#include <iostream> 
#include <fstream> // to both read & write to files
using namespace std;

/* Open text file and read each line to print it on terminal, then close */ 
int main () {
  string line;
  ifstream myfile;
  myfile.open ("test2.txt"); // open text file
  
  // read file lines
  while(getline(myfile,line)){
    cout << line << "\n" ;
  }
  
  cout<<"\n \n ^^^DONE: This is the text in test2.txt "<<endl;
  
  myfile.close();
  
  return 0;
}

