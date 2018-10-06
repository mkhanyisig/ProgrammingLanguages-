#include <iostream>

using namespace std;

int main()
{
   cout << "Welcome to my C++ control flow statements demo" << endl; 
   int a=10;
   int b=19;
   int c=-5;
   
   // C++ control staments include either compound or single statements separated by semicolon (;) and wrapped around brackets {}
   
   
   // selection statements if & else use example
   if(a%2==1){ // if odd
       cout << "a is odd. a=" <<a<< endl;
   }
   else if(a%2==0){
       cout << "a is even. a=" <<a<< endl;
   }
   else{
       cout << "Something wrong with your a value, it is not an int. a=" << a<< endl;
   }
   
   // iteration examples 
   
   //for loop 
   cout <<"for loop" << endl;
   for(int i=0;i<3;i++){
       cout << i << endl;
   }
   
   // while loop
   cout << "while loop" << endl;
   while(c<0){
       cout << c << endl;
       c++;
   }
   
   // do loop
   cout << "do loop " << endl;
   do{
       cout << c << endl;
       c--;
   } while (c>-5);
   
    
    // JUMP Statements demonstration
    
    // break jump statement
    cout << "break statement demo" << endl;
    for(int i=0;;i++){ // fo loop with no ending condition
        // raise c to +2
        cout << c << endl;
        c++;
        if(c==2){ // ending statement here
            cout << "terminating condition c=" <<c<<"  ** break "<< endl;
            break;
        }
        
        
    }
    
    // continue jump satement
    cout << "\n break statement demo" << endl;
    for(int i=0;i<6;i++){ // count up to 5 and omit 3
        if(i==3){
            continue;
        }
        cout <<i<< ", " << endl;
    } 
    cout << "Go!!!" << endl;
    
    // goto example
    int n=1;
    cout << "\ngoto statement demo" << endl;
    cout << "ABC, easy as " << endl;
    mylabel: // reference point
    cout << n << ",";
    n++;
    if (n<4){goto mylabel;}
    
    
    cout << "\nsing along";
    
    // switch example
    cout << "\n\nswitch statement demo:" << endl;
    int x=7; // 
    cout << "I am in year "<<x<<" at Colby,  so I what class year am I ? ==> ";
    
    switch (x) {
        case 1:
            cout << "Freshman 2021"<< endl;
            break;
        case 2:
            cout << "Sompmore 2020"<< endl;
            break;
        case 3:
            cout << "Junior 2019"<< endl;
            break;
        case 4:
            cout << "Senior :) 2018"<< endl;
            break;
        /*case (x>4):
            cout << "Alumni"<< endl;
            break; */
        default:
            cout << "I dont know man :("<< endl;
        }
    
    
    
    
   
   
   return 0;
}