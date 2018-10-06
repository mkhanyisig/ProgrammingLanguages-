#include <stdlib.h>
#include <stdio.h>
 
 
/*
	reference source: https://cboard.cprogramming.com/c-programming/92865-trying-generate-bus-error.html
*/ 
 
int main()
{
    void *ptr;
    int i;
 
    ptr = malloc(2 * sizeof(int) - 1);
    if (malloc != NULL)
    {
        for (i = 0; i < sizeof(int); i++)
        {
            * (int *) ((int) ptr + i);
        }
 
        free(ptr);
 
        printf("Looks like no memory alignement error happened\n");
    }
 
    else
    {
        printf("Error while allocating memory\n");
    }
 
    getchar();
 
    return 0;
}