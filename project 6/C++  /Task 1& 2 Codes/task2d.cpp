/*
*	Mkhanyisi Gamedze
*	CS333 Programming languages
*	10 November 2017
*	C++: Functions and File I/O
*/

#include <iostream>
#include <fstream>

/* demonstrating an example dynamic function in c++, the "auto" function which deduces output type from input parameter types  */  
 
int add(int x, int y){
    return x + y;
}
 
int main(){
    auto sum = add(5, 6); // add() returns an int type, -> sum is then  type int
    std::cout<<"sum is of type: "<<typeid(sum).name()<<std::endl;
    
    return 0;
}