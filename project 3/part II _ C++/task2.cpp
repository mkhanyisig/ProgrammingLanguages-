#include <iostream>
using namespace std;

bool binarySearch(int list[], int value, int min, int max ){
    // print the list inputs
    cout << "value: "<<value<<" min: "<<min<<"  max: "<<max<< endl;
    
    
    // first check condition that value is not in list
    if(min>max){
        cout << "Your value  "<<value<<"  is not in this list sorry "<< endl;
        return false;
    }
    else{
        int center=(int)((max+min)/2);
        if(list[center]<value){
            // search the right side
            binarySearch(list, value, center, max); // recursion
        }
        else if(list[center]>value){
            // search left side
            binarySearch(list, value, min, center); // recursion
        }
        else{
            cout << "We found your value : "<<value<< endl;
            return true;
        }
    }
}

int main(){
   cout << "Hello Mkhanyisi lets search for your value!!!" << endl; 
   
   int n[ 100 ]; //  an array of 100 integers
 
   // initialize elements of array n to 0          
   for ( int i = 0; i < 100; i++ ) {
      n[ i ] = i ;
   }
   
   binarySearch(n, 66,0,99);
   
   return 0;
}