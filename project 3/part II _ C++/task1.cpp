#include <stdio.h>

// basic data types
// the scope of these two variables covers the entire code
int a=10;
float b=10.5;

int main()
{   
    // all vriables here, the scope of the main function only
    // basic data types
    double Atoms = 2500000; // used to define BIG floating point numbers. It reserves twice the storage for the number
    char letter='a';
    char charArray[15]="derrick rose";
    int array[8]={1,2,3,4,5,6,7,8};

    // modifiers
    long int d=15096853653;
    short int e=0;
    signed int f=-35;
    unsigned int g=44;
    printf("* value of a %d : the global value \n ****** \n \n ",a);
    // demonstrating scoping 
    int a=5;
    for(int a=7;a>0;a--){
        printf("value of a %d\n",a);
        
    }
    printf(" ****\n value of a after forloop %d : the non-local value\n",a);
    

    
    printf("Cleveland cavaliers boy !\n");

    return 0;
}