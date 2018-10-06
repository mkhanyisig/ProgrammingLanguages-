/**
		 * CS 333 Programming Languages FA17
		 * Project 5  task 2: polymorphism
		 *
		 * Mkhanyisi Gamedze
		 * 23 October 2017
*/


#include <iostream>
#include <string>

using namespace std;

class Player {  
   public:
      int age, weight;
      string name;
      Player( int a = 0, int b = 0, string id="player"){
         age = a;
         weight = b;
         name=id;
      }
      int identity() {
         cout << "Player profile . Name: "<<name <<"  age: "<<age<<endl;
         return 0;
      }
      
      void about(){
      	cout << "Player  "<<name<<endl;  
      }
};

class Messi: public Player { // specific player is a descendant of the parent 
   public:
      Messi( int a = 0, int b = 0, string id1="Lionel Messi"):Player(a, b, id1) { } // inheriting the init method as well
      
      int identity () { 
         cout << "Name "<<name <<"  Age:"<<age <<"  ,  Playing position	Forward"<<endl;
         return 0; 
      }
      void about(){
      	cout <<"\n  "<< name<<"\nPortuguese professional footballer who plays as a forward for Spanish club Real Madrid and the Portugal national team. Often considered the best player in the world and widely regarded as one of the greatest of all time  "<<endl; 
      }
};


class Ronaldo: public Player {  // specific player is a descendant of the parent 
   public:
      Ronaldo( int a = 0, int b = 0, string id1="Christiano Ronaldo"):Player(a, b, id1) { } // inheriting the init method as well
      
      int identity () { 
         cout << "Name "<<name <<"  Age:"<<age <<"  ,  Playing position	Forward"<<endl;
         return 0; 
      }
      void about(){
      	cout << "\n  "<<name<<"\nArgentine professional footballer who plays as a forward for Spanish club FC Barcelona and the Argentina national team. Often considered the best player in the world and regarded by many as the greatest of all time, Messi is the only player in history to win five FIFA Ballon d'Or awards  "<<endl; 
      }
};

int main(){
   cout << "polymorphism demo" << endl; 
   // create parent pointers
   Player *ptr1;
   Player *ptr2;
   Messi *ptr1a;
   Ronaldo *ptr2a;
   
   // since pointers can point to objects in C++, I point parent class ptr, to child object
   Player c1= Messi(46, 120, "Lionel Andrés Messi");
   Player c2=Ronaldo(23, 85, "Cristiano Ronaldo dos Santos Aveiro");
   // using child pointers
   Messi c1a=Messi(46, 120, "Lionel Andrés Messi");
   Ronaldo c2a=Ronaldo(23, 85, "Cristiano Ronaldo dos Santos Aveiro");
   
   ptr1=&c1;
   ptr2=&c2;
   ptr1a=&c1a;
   ptr2a=&c2a;
   
   // the difference
   cout << "\nUsing Player class pointers " << endl; 
   ptr1->identity();
   ptr2->identity();
   c1.identity();
   c2.identity();
   cout << "\n \n About these players" << endl; 
   ptr1->about();
   ptr2->about();
   c1.about();
   c2.about();
   
    cout << "\nUsing the current class reference" << endl; 
    ptr1a->identity();
    ptr2a->identity();
    c1a.identity();
    c2a.identity();
    ptr1a->about();
    ptr2a->about();
    c1a.about();
    c2a.about();
   return 0;
}