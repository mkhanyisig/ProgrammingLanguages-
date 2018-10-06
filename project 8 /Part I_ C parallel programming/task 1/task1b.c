/**
 *
 *   Mkhanyisi Gamedze
 *  CS333: Programming languages
 *	Linked list C file
 *  project 8:  Part I: Parallel Programming in C
 * 	28 December 2017 
 */

/*  Using two threads to reduce the computing time for the merge sort list, through splitting list in half and then soring
- still debugging the multithreaded merge sort

This source gave me a good outline on the merge and mergesort general algorithms: 
https://github.com/sangeeths/stackoverflow/blob/master/two-threads-parallel-merge-sort.c   */ 


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int NOTHREADS=2;  // the number of parallel processors

/*your list to sort */
int a[] = {28 ,18, 9, 23, 33, 16, 3, 41, 38, 00, 14, 47, 13, 50, 17, 8, 26, 45, 40, 46,22};
 
typedef struct node {
    int i;
    int j;
    int tid;
} NODE;   // will hold thread beginning and end indexes


// q-sort comparator
int comparator (const void *num1, const void *num2){
	return (*(int*)num1 - *(int*)num2);
}

void merge(int i, int j){
		/* Given the two indices, this function merges the contents between the two indices 
		and sorts them, using merge sort algorithm  */
        int mid = (i+j)/2;
        int ai = i;
        int bi = mid+1;
        int newa[j-i+1], newai = 0;
        while(ai <= mid && bi <= j) {
                if (a[ai] > a[bi])
                        newa[newai++] = a[bi++];
                else                    
                        newa[newai++] = a[ai++];
        }
        while(ai <= mid) {
                newa[newai++] = a[ai++];
        }
        while(bi <= j) {
                newa[newai++] = a[bi++];
        }
        for (ai = 0; ai < (j-i+1) ; ai++)
                a[i+ai] = newa[ai];
}

void * mmergesort(void *a){
        NODE *p = (NODE *)a;
		/*  Apply multithreading concepts to sort arrays: uses four threads : use 2 threads  */
			
		NODE ti[2];
		pthread_t thread[2];
        int mid = (p->i+p->j)/2;
        int ret;
		
		// split array into two distinct subsections
		
			ti[0].i = p->i;
			ti[0].j = mid;
			ti[1].i = mid+1;
			ti[1].j = p->j;
			
			if (p->i >= p->j) return 0;   // error handling check (if begin>end)
    
        for(int i=0;i<2;i++){
			ret =pthread_create(&thread[i], NULL, mmergesort, &(ti[i]));
			if (ret) {
					printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
					exit(1);
			}
        }
        for(int i=0;i<2;i++){
        	pthread_join(thread[i], NULL);
        }
        merge(p->i, p->j);  // merge from start index to final index
        pthread_exit(NULL);
		
		
		return 0;
		
}


int main(){
        int i;
        NODE ti[NOTHREADS];
        int size=21/NOTHREADS;
		for(int i=0;i<NOTHREADS;i++){        
			ti[i].i = i*size;
			ti[i].j = (i+1)*size;
			ti[i].tid=i;
		}
        
        pthread_t tid[NOTHREADS];

        int ret; 

        for(int i=0;i<NOTHREADS;i++){
			ret =pthread_create(&tid[i], NULL, mmergesort, &(ti[i]));
			if (ret) {
					printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
					exit(1);
			}
        }

        for(int i=0;i<NOTHREADS;i++){
        	pthread_join(tid[i], NULL);
        }
		
		
		
        for (i = 0; i < 20; i++)
                        printf ("%d ", a[i]);
        printf ("\n");

        // pthread_exit(NULL);
        return 0;
}