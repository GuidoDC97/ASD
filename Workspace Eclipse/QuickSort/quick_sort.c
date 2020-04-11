#include "vector.h"

void swap(vector* vector, int idx_a, int idx_b){
	int temp = vector->v[idx_a];
	vector->v[idx_a] = vector->v[idx_b];
	vector->v[idx_b] = temp;
}


int partition(vector* vector, int p, int r){
	int pivot = vector->v[r];

	int i = p-1;
	for(int j = p; j<r; j++){
		if(vector->v[j] < pivot){
			i++;
			swap(vector, i, j);
		}
	}

	swap(vector, i+1, r);

	return i+1;
}

void quick_sort(vector* v, int p, int r){

	if(p<r){
		int q = partition(v, p, r);
		quick_sort(v, p, q-1);
		quick_sort(v, q+1, r);
	}

}
