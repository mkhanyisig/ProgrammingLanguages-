/**
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */


#include <iostream>
#include <thread> 
using namespace std;
void threadFunc()
{
	cout << "Welcome to Multithreading" << endl;

}
void printSomeValues(int val, char* str, double dval)
{
	cout <<"Your values  :  " <<val << " " << str <<" " << dval << endl;

}

int main()
{
	//pass a function to thread
	thread funcTest1(threadFunc);
	
	//detach funcTest1 from main thread
    funcTest1.detach();
    if (funcTest1.joinable()){
	    //main is blocked until funcTest1 is not finished
	    funcTest1.join();
    }
    else{
	    cout << "functTest1 is detached" << endl;
    }
    
    
    char* str = "Hello";
    //5, str and 3.2 are passed to printSomeValues function
    thread paramPass(printSomeValues, 5, str, 3.2);
    if (paramPass.joinable())
        paramPass.join();
    }
    
    // illistrating unique thread id's
    //create 3 different threads
    thread t1(threadFunc);
    thread t2(threadFunc);
    thread t3(threadFunc);
    //get id of all the threads
    thread::id id1 = t1.get_id();
    thread::id id2 = t2.get_id();
    //join all the threads
    if(t1.joinable()){
	    t1.join();
	    cout << "Thread with id " << t1.get_id() << " is terminated" << endl;
    }
    if(t2.joinable()){
	    t2.join();
	    cout << "Thread with id " << t2.get_id() << " is terminated" << endl;
    }
  

    