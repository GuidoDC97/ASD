#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

typedef struct {
	int* v;
	int dim;
	int dim_heap;
}heap;


void init(heap* heap, int d);
void fill_random_vector(heap* heap);
void fill_rev_sorted_vector(heap* heap);
void fill_sorted_vector(heap* heap);
void print_vector(heap* heap);
void destroy(heap* heap);

void max_heapify(heap* heap, int idx);
void build_max_heap(heap* heap);
void heap_sort(heap* heap);
#endif
