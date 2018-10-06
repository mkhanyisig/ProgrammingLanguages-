Mkhanyisi Gamedze 
CS333 Project 7
24 December 2017

Compiler used: terminal 
macOS Sierra version 10.12.6

*****Part I: Parallel Programming in C

Task 1 ->

After multiple attempts to figure out a way to use parallelism to sort my array, my project culminated in 
my two solutions to this task. My initial attempt to this problem was using the merge sort algorithm, through 
splitting the array into N sections for N threads, sorting those sub arrays & then merging the result. I was able to get my 
algorithm to work in sorting the N subsections, but merging the result posed  bigest hurdle. I could get my algorithm to sort well for 
two threads, but for a higher order sort, I could not get it to merge the results. That is where I left with my first attempt, which 
was inspired by my reference sources. This attempt file can be found on my two_thread_merge.c. 
To complete the first task, inspired by a conversation with Nile  and class source code examples, I used a thread struct to hold an array 
object and other fields, for the thread information. The threadsort function takes in a pointer to the array and also the section length to sort. 
Given this information, I then create an array of thread objects that then sort each sublist and then merges the final result, through joining the threads. 
Each thread sorts the subarray using qsort and then gives out the final result. 
To test my final program, I allocated two big arrays memory, to hold random integers. I then run the whole system using thread sort, which uses the
default number of threads to do the sorting. This I compare to the regular qsort. The times for different number of threads used can be found on 
-> pic 1
  I got the minimum time for 12 threads. 
  
Task 1b is my unsuccesful to use multi threading on the mergesort algorithm. 

Task 2 ->

Using the same code structure from task 1, I added a thread sort algorithm, which applies the filter for each section length group of pixels. 
The output images from testing my code are
->multiple parrallell threads time
->serial processing time


*****Part II

-> Check wiki pages

*****Extenstions

->Using mutex for a phone booth code example, my use controlled access to a critical section. 
For a phone booth the door represents the critical section. This example was in C++, phone_booth.cpp



