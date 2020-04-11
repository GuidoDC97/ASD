#include "Heap_Sort.h"
#include <stdlib.h>
#include <stdio.h>

#define LEFT(i) (i*2 + 1);
#define RIGHT(i) (i*2 + 2);
#define PARENT(i) (i/2);

void init(heap* heap, int d){
	heap->v = malloc(d*sizeof(int));
	heap->dim = d;
	heap->dim_heap = 0;
}

void fill_random_vector(heap* heap){
	for(int i=0; i< heap->dim; i++){
		heap->v[i] = rand()%100;
	}
}

void fill_rev_sorted_vector(heap* heap){
	for(int i=0, j = heap->dim; i< heap->dim; i++, j--){
		heap->v[i] = j;
	}
}

void fill_sorted_vector(heap* heap){
	for(int i=0; i< heap->dim; i++){
		heap->v[i] = i;
	}
}
void print_vector(heap* heap){
	printf("[");
		for(int i=0; i< heap->dim; i++){
			if(i == heap->dim-1)
			printf("%d",heap->v[i]);
		else
			printf("%d,",heap->v[i]);
	}
	printf("]\n");
	fflush(stdout);
}

void destroy(heap* heap){
	free(heap->v);
}

void swap(heap* heap, int idx_a, int idx_b){
	int temp = heap->v[idx_a];
	heap->v[idx_a] = heap->v[idx_b];
	heap->v[idx_b] = temp;
}

void max_heapify(heap* heap, int idx){

	int l = LEFT(idx);
	int r = RIGHT(idx);
	int max = idx;

	if(l < heap->dim_heap && heap->v[idx] < heap->v[l])
		max = l;
	if(r < heap->dim_heap && heap->v[max] < heap->v[r])
		max = r;
	if(max != idx){
		swap(heap, idx, max);
		max_heapify(heap, max);
	}

}

void build_max_heap(heap* heap){
	heap->dim_heap = heap->dim;

	for(int i= (heap->dim_heap -1)/2; i>=0; i--){
		max_heapify(heap, i);
	}

}

void heap_sort(heap* heap){
	build_max_heap(heap);

	for(int i=heap->dim-1; i>0; i--){
		swap(heap, 0, i);
		heap->dim_heap--;
		max_heapify(heap, 0);
	}

}
