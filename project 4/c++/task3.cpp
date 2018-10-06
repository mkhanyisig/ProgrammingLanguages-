 #include <iostream>
#include<stdio.h>
 

/*
*	Bubble Sort sort program in my main function
* 
*/


using namespace std;
 
int main()
{
    int num,temp_val;
    char response; // yes or no
    
    cout<<"Enter own array or use random array ? Enter y/n  \n";
    cin>>response;
    
    
    int a[20];
    
    if(response=='y'){
    	cout<<"response: yes \n";
    	// using the library I found the following interesting method to make the program more interactive
    	cout<<"Enter the size of array you want to build(<20): ";
    	cin>>num;
    	cout<<"Please enter "<<num<<" new array elements in any order you want \n "; 
    
    	for(int i=0;i<num;++i){ // build array
    	    cin>>a[i]; // take in input and insert it onto the array
    	} 
     }
     else if(response=='n'){
     	cout<<"response: no"<< endl;
     	// use default array
     	num=22;
     	
     	// Fill my array with random numbers in [-50,50]
    	for(int i = 0; i < 22; i++){
        	a[i] = (rand() % 101)-50;   // build integer array
    	}
    	
    	// print out array
    	cout<<"Before bubble sort: \n ";
    	for(int i=0;i<num;++i){
        cout<<" "<<a[i];
    	} cout <<"\n";
    	
    	

    	cout<<"done buling array \n \n";
     }  
     
     
    
    // bubble sort forloop algorithm
    for(int i=1;i<num;++i){
        for(int j=0;j<(num-i);++j){
            if(a[j]>a[j+1]){
                temp_val=a[j];
                a[j]=a[j+1];
                a[j+1]=temp_val;
            }
        }
    }
    
    cout<<"After bubble sort: \n ";
    for(int i=0;i<num;++i){
        cout<<" "<<a[i];
    } cout <<"\n";
        
    return 0;
}