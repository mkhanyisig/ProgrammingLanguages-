#include <iostream>
using namespace std;



int main(){
   cout << "Hello Mkhanyisi lets search for your value!!!" << endl; 
   
   // declare variables to be manipulated
    double Atoms = 2500000; 
    char l1='a';
    char l2='b';
    char l3[10]="colby  ";
    char l4[10]="college";
    char charArray[15]="derrick rose";
    int array[8]={1,2,3,4,5,6,7,8};
    int a=5;
    int b=66;
    int c=-74;
    float x=12.333;

    // modifiers
    long int d=15096000000;
    short int e=222;
    signed int f=-35;
    unsigned int g=44;
    
    // exploring operators on different types of ints
    cout << "int + long int gives " <<b+d<<"  type :"<< typeid(b+d).name()<< endl;
    
    cout << "short int + long int gives " <<d+e<<"  type :"<< typeid(d+e).name()<< endl;
    
    cout << "signed int + short int gives " <<f+e<<"  type :"<< typeid(f+e).name()<< endl;
    
    cout << "int - long int gives " <<b-d<<"  type :"<< typeid(b-d).name()<< endl;
    
    cout << "short int - long int gives " <<d-e<<"  type :"<< typeid(d-e).name()<< endl;
    
    cout << "signed int - short int gives " <<f-e<<"  type :"<< typeid(f-e).name()<< endl;
    
    cout << "short int / long int gives " <<d/e<<"  type :"<< typeid(d/e).name()<< endl;
    
    cout << "signed int % short int gives " <<f%e<<"  type :"<< typeid(f%e).name()<< endl;
    
    cout << "short int % long int gives " <<d%e<<"  type :"<< typeid(d%e).name()<< endl;
    
    
    
    // exploring int and float 
    cout << "float + signed int gives " <<x+f<<"  type :"<< typeid(f+x).name()<< endl;
    
    cout << "float - signed int gives " <<x-f<<"  type :"<< typeid(x-f).name()<< endl;
    
    cout << "float / short int gives " <<f/e<<"  type :"<< typeid(f/e).name()<< endl;
    
     cout << "float % short int gives " <<f%e<<"  type :"<< typeid(f%e).name()<< endl;
    
    
    // exploring character strings
    cout << "char + char " <<l1+l2<<"  type :"<< typeid(l1+l2).name()<< endl;
    
    cout << "char + char[] " <<l1+l4<<"  type :"<< typeid(l1+l4).name()<< endl;
    
    cout << "char + char[] " <<l4+l1<<"  type :"<< typeid(l4+l1).name()<< endl;
    
    
    
    
   
   return 0;
}