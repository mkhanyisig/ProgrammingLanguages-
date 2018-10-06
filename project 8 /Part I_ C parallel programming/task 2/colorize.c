/**
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ppmIO.h"
#include <time.h>

#define NUM_THREADS 2

// struct object to hold all thread fields
typedef struct{
	Pixel *src;
	int rows; 
	int cols;
	int colors;
	int section_len;
	int tid;
} tdInfo;  // thread info

void *filter_image(void *ud){
	tdInfo *ti = (tdInfo *)ud;
	//pthread_mutex_lock(&mutex);
	for(int i=0; i<ti->section_len; i++) {
		ti->src[i].r = ti->src[i].r > 128 ? (220+ti->src[i].r)/2 : (30+ti->src[i].r)/2;
		ti->src[i].b = ti->src[i].b > 128 ? (220+ti->src[i].g)/2 : (30+ti->src[i].g)/2;
		ti->src[i].g = ti->src[i].g > 128 ? (220+ti->src[i].b)/2 : (30+ti->src[i].b)/2;
	}
	return 0;
	//pthread_mutex_unlock(&mutex);
}



int main(int argc, char *argv[]) {
	Pixel *src;
	int rows, cols, colors;
	clock_t start, end;
	tdInfo t[NUM_THREADS];
	pthread_t thread[NUM_THREADS];
	

	// check usage
	if( argc < 2 ) {
		printf("Usage: %s <image filename>\n", argv[0]);
		exit(-1);
	}

	// read image and check for errors
	src = ppm_read( &rows, &cols, &colors, argv[1] );
	
	// divide up the work
	for(int i=0; i<NUM_THREADS; i++){
		t[i].tid = i;
		t[i].src = &(src[i*(rows*cols/NUM_THREADS)]);
		t[i].section_len = (int)rows*cols/NUM_THREADS;
		t[i].rows = rows;
		t[i].cols = cols;
	}

	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	//process image with each thread and measure the time taken
	start = clock();
	for(int i=0; i<NUM_THREADS; i++){
		pthread_create(&thread[i], NULL, filter_image, &(t[i]));
	}
	// join threads
	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(thread[i], NULL);
	}
	end = clock();

	// output image
	ppm_write( src, rows, cols, colors, "bold.ppm" );
	printf("Parallel processing using %d threads ->  time: %f\n", NUM_THREADS,(double)(end - start) / CLOCKS_PER_SEC);
	free(src);

	return(0);
}

	
