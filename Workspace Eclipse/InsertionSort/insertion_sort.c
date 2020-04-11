#include <stdio.h>
#include <time.h>
#include "vector.h"

void insertion_sort(vector* vector){

	for(int i=1; i< vector->dim; i++){
		int key = vector->v[i];

		int j = i-1;
		while(j>= 0 && vector->v[j]>key){
			vector->v[j+1] = vector->v[j];
			j=j-1;
		}
		vector->v[j+1] = key;
	}

}

void insertion_sort_f(double* vector, int dimension){

	for(int i=1; i< dimension; i++){
		float key = vector[i];
		//printf("\n\n %f \n\n",vector[i]);
		int j = i-1;
		while(j>= 0 && vector[j]>key){
			vector[j+1] = vector[j];
			j=j-1;
		}
		vector[j+1] = key;
		//printf("\n\n %f \n\n",vector[j+1]);
	}

}
