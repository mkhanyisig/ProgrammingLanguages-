/*
 *
 *  Mkhanyisi Gamedze
 *  CS333: Programming languages
 *  project 8:  Part I: Parallel Programming in C
 * 	10 January  2017 
 */



#include <stdio.h>
#include <stdlib.h>
#include "ppmIO.h"
#include <time.h>

int main(int argc, char *argv[]) {
	Pixel *src;
	int rows, cols, colors;
	int i;
	clock_t start, end;

	// check usage
	if( argc < 2 ) {
		printf("Usage: %s <image filename>\n", argv[0]);
		exit(-1);
	}

	// read image and check for errors
	src = ppm_read( &rows, &cols, &colors, argv[1] );
	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	// process image (time the operation)
	start = clock();
	for(i=0;i<rows*cols;i++) {
		src[i].r = src[i].r > 128 ? (220+src[i].r)/2 : (30+src[i].r)/2;
		src[i].g = src[i].g > 128 ? (220+src[i].g)/2 : (30+src[i].g)/2;
		src[i].b = src[i].b > 128 ? (220+src[i].b)/2 : (30+src[i].b)/2;
	}
	end = clock();

	// write out the image
	ppm_write( src, rows, cols, colors, "bold2.ppm" );
	printf("Serial processing   time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(src);

	return(0);
}

	
