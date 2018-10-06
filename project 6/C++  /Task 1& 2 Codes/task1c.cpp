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

/* Interactive c++ main method, to get user input and then give return value */ 
int main () {
	
	string name, sport, fav;
	
	cout << "What is your name? \n";

	cin >> name;

	cout << "\n what is you favourite sport? \n";
	
	cin >> sport;
	
	cout << "\nIn that sport, which team do you support? \n";
	
	cin >> fav;
	
	cout<<"\n\n"<< name<<" likes  "<<sport<< " and his favourite team is (the)  "<<fav<<endl;
	
  return 0;
}
