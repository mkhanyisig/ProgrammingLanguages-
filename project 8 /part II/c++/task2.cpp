/**
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */


// task 2 C++


#include <iostream>
#include <thread>
#include <pthread.h>
#include <mutex>  
using namespace std;

#define NUM_THREADS 100

// struct object to hold all thread fields
typedef struct{
	int *array;
	int size; 
	int section_len;
	int tid;
} tdInfo;  // thread info

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

void *sort(void *threadinfo){
	/* Sort the array in each thread  */
	tdInfo *ti = (tdInfo *) threadinfo;
	qsort(ti->array, ti->section_len, ti->size, compare);
	return 0;
}

void threadSort(void *array, int length){
	/* Use N threads to sort smaller subl-arrays & then merge results. QSort merged final array  */
	int *arr = (int*)array;
	tdInfo ti[NUM_THREADS];
	pthread_t thread[NUM_THREADS];
	
	// split the work into appropriate subsections for threads
	for(int i=0; i<NUM_THREADS; i++){
		ti[i].tid=i;
		ti[i].array = &(arr[i*(length/NUM_THREADS)]);
		ti[i].section_len = length/NUM_THREADS;
		ti[i].size = sizeof(int);
	}
		for(int i =0; i<NUM_THREADS; i++){
		pthread_create(&thread[i], NULL, sort, &ti[i]);
	}
	for (int i = 0; i<NUM_THREADS; i++){
		pthread_join(thread[i], NULL);
	}
	qsort(arr, length, sizeof(int), compare);	
}

int main(){
	const int size=100000; 
	clock_t start, end; 
	int *bigarray=(int *)malloc(sizeof(int)* size);
	int *bigarray2=(int *)malloc(sizeof(int)* size);
	
	// fill arrays with random numbers
	for(int i=0;i<size;i++){
		bigarray[i]=rand();
		bigarray2[i]=rand();
	}
	
	// time parallel threading sort process
	start = clock();
    threadSort(bigarray, size);
    end = clock();
    printf("Parallel sorting using %d threads  : %f \n",NUM_THREADS ,(double)(end - start) / CLOCKS_PER_SEC);
    
    // time normal q-sort to compare times
    start = clock();
    qsort(bigarray2, size, sizeof(int), compare);
    end = clock();
    printf("Normal quicksort  : %f \n",(double)(end - start) / CLOCKS_PER_SEC);
	
	
	return 0;
}
    
  

    