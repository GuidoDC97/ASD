#ifndef VECTOR_
#define VECTOR_

typedef struct{
	int* v;
	int dim;
}vector;

void print_vector(vector* vector);
void create_random_vector(vector* vector, int dim);
void destroy_vector(vector* vector);
void create_sorted_vector(vector* vector, int dim);

#endif
