#include "vector.h"
#include <Math.h>
#include <stdio.h>
#include <stdlib.h>

void merge(vector* A, int p, int q, int r){

	int n1 = q-p+1;
	int n2 = r-q;

	int* L = malloc((n1+1)*sizeof(int));
	int* R = malloc((n2+1)*sizeof(int));
	for(int i=0; i<n1; i++){
		L[i] = A->v[p+i];
	}
	for(int j=0; j<n2; j++){
		R[j] = A->v[q+j+1];
	}
	L[n1] = 100;
	R[n2] = 100;

	int i = 0, j = 0;
	for(int k=p; k<=r; k++){

		if(L[i] <= R[j]){
			A->v[k] = L[i];
			i++;
		}else{
			A->v[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
}

void merge_f(double* A, int p, int q, int r){

	int n1 = q-p+1;
	int n2 = r-q;

	double* L = malloc((n1+1)*sizeof(double));
	double* R = malloc((n2+1)*sizeof(double));
	for(int i=0; i<n1; i++){
		L[i] = A[p+i];
	}
	for(int j=0; j<n2; j++){
		R[j] = A[q+j+1];
	}
	L[n1] = 100;
	R[n2] = 100;

	int i = 0, j = 0;
	for(int k=p; k<=r; k++){

		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
}
void merge_sort(vector* A, int p, int r){
	if(p<r){
		int q = p+(r-p)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

void merge_sort_f(double* A, int p, int r){
	if(p<r){
		int q = p+(r-p)/2;
		merge_sort_f(A,p,q);
		merge_sort_f(A,q+1,r);
		merge_f(A,p,q,r);
	}
}
