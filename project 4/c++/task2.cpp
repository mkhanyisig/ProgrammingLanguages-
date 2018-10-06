 #include <iostream>

using namespace std;

int add(int a){
    // add 6 to input
    return a+6;
}

int main()
{
   cout << "Demo" << endl; 
   
   // declare function variable
   auto function=add;
   
   // demonstrate function used as data type
   cout << "Output of func with 16 input :"<<function(16) << endl; 
   // print out type id
   cout << " function data type id :" <<typeid(function).name()<< endl; 
        
   return 0;
}