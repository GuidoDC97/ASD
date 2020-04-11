#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void create_random_vector(vector* vector, int dim){
	vector->dim = dim;
	vector->v = malloc(dim*sizeof(int));


	for(int i=0; i< vector->dim; i++){
		vector->v[i] = rand()%100;
	}
}

void create_sorted_vector(vector* vector, int dim){
	vector->dim = dim;
	vector->v = malloc(dim*sizeof(int));


	for(int i=0; i< vector->dim; i++){
		vector->v[i] = i;
	}
}


void create_rev_sorted_vector(vector* vector, int dim){
	vector->dim = dim;
	vector->v = malloc(dim*sizeof(int));


	for(int i=0, j = dim-1; i< vector->dim; i++, j--){
		vector->v[i] = j;
	}
}

void destroy_vector(vector* vector){
	free(vector->v);
}

void print_vector(vector* vector){
		printf("[");
		for(int i=0; i< vector->dim; i++){
			if(i == vector->dim-1)
				printf("%d",vector->v[i]);
			else
				printf("%d,",vector->v[i]);
		}
		printf("]\n");
		fflush(stdout);
}
