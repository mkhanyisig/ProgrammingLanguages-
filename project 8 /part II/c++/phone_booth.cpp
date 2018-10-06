
/**
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */


// reference source: https://www.tutorialcup.com/cplusplus/multithreading.htm#Initializing-thread-with-a-function

// This example counts as my extension for ->Demonstrating the use of a semaphore or mutex lock to control access to a critical section.

#include <iostream>
#include <thread>
#include <mutex>  
using namespace std;

mutex m;//door handle
void makeACall(){
	m.lock();//person enters the call box and locks the door
	//now it can talk to his friend without any interruption
	cout << " Hello my friend, this is " << this_thread::get_id() << endl;
	//this person finished to talk to his friend
	m.unlock();//and he leaves the call box and unlock the door
}
int main(){
	//create 3 persons who want to make a call from call box
	thread person1(makeACall);
	thread person2(makeACall);
	thread person3(makeACall);
	if (person1.joinable()){
		person1.join();
	}
	if (person2.joinable()){
		person2.join();
	}
	if (person3.joinable()){
		person3.join();
	}
}
    
  

    