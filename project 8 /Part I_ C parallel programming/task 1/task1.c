/**
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 30

// struct object to hold all thread fields
typedef struct{
	int *array;
	int size; 
	int section_len;
	int tid;
} tdInfo;  // thread info

// q-sort comparator
int comparator (const void *num1, const void *num2){
	return (*(int*)num1 - *(int*)num2);
}


void *sort(void *threadinfo){
	/* Sort the array in each thread  */
	tdInfo *ti = (tdInfo *) threadinfo;
	qsort(ti->array, ti->section_len, ti->size, comparator);
	return 0;
}

void tdSort(void *array, int length){
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
	qsort(arr, length, sizeof(int), comparator);
}


int main(int argc, char *argv[]){
	
	const int size=100000; 
	clock_t start, end; 
	int *bigarray=malloc(sizeof(int)* size);
	int *bigarray2=malloc(sizeof(int)* size);
	
	// fill arrays with random numbers
	for(int i=0;i<size;i++){
		bigarray[i]=rand();
		bigarray2[i]=rand();
	}
	
	// time parallel threading sort process
	start = clock();
    tdSort(bigarray, size);
    end = clock();
    printf("Parallel sorting using %d threads  : %f \n",NUM_THREADS ,(double)(end - start) / CLOCKS_PER_SEC);
    
    // time normal q-sort to compare times
    start = clock();
    qsort(bigarray2, size, sizeof(int), comparator);
    end = clock();
    printf("Normal quicksort  : %f \n",(double)(end - start) / CLOCKS_PER_SEC);
	
	
	return 0;
}
