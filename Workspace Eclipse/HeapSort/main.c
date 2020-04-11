#include "Heap_Sort.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//#include <Windows.h>

double execute_sorting(int dimension);
void write_file(int dimension, double elapsed_time);
double extract_median_time(double* time_v, int dimension);
void insertion_sort_f(double* vector, int dimension);

int main(){

	int dim, step, trials;
	int condition = 1;

	do{
		condition = 1;

		printf("Enter vector dimension: ");
		scanf("%d", &dim);
		printf("Enter step: ");
		scanf("%d", &step);
		printf("Enter n of trial for step: ");
		scanf("%d", &trials);

		if(step > dim){
			printf("Insert correct number of step.\n");
			condition = 0;
		}
	}while(!condition);


	srand(time(0));

	double time_v [trials];
	double median_time = 0;
	int reps = step;
	while(reps <= dim){
		printf("Sorting %d elements vector %d times.\n",reps, trials);

		for(int i=0; i<trials; i++){
			printf("Repetition %d\n",i+1);
			time_v[i] = execute_sorting(reps);
			//printf("time_v[%d]: %f\n",i, time_v[i]);
		}
		median_time = extract_median_time(time_v, trials);
		write_file(reps, median_time);
		reps += step;
	}

	system("pause");
	return 0;
}



double execute_sorting(int dimension){


	heap heap;
	init(&heap, dimension);

	fill_random_vector(&heap);
	//print_vector(&heap);
	printf("\nSORTING...\n\n");
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	heap_sort(&heap);
	clock_gettime(CLOCK_MONOTONIC, &end);

	/*	double start =0 , end =0;
		FILETIME a,b,c,d;
		FILETIME a1,b1,c1,d1;
		GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d);
		heap_sort(&heap);
		GetProcessTimes(GetCurrentProcess(),&a1,&b1,&c1,&d1);
		double user = (double)(d.dwLowDateTime | ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
		double kernel = (double)(c.dwLowDateTime | ((unsigned long long)c.dwHighDateTime << 32)) * 0.0000001;
		start = kernel + user;
		user = (double)(d1.dwLowDateTime | ((unsigned long long)d1.dwHighDateTime << 32)) * 0.0000001;
		kernel = (double)(c1.dwLowDateTime | ((unsigned long long)c1.dwHighDateTime << 32)) * 0.0000001;
		end = kernel + user;*/


	double elapsed_time;
	//elapsed_time = end - start;
	elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
	elapsed_time = (elapsed_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
	printf("Elapsed time: %fs.\n", elapsed_time);
	//print_vector(&heap);

	destroy(&heap);

	return elapsed_time;
}

double extract_median_time(double* time_v, int dimension){
	double median = 0;

//	printf("[DEBUG] Vettore tempi NON ordinato: [" );
//		for(int i=0; i< dimension; i++){
//			printf("%f", time_v[i]);
//		}
//	printf("]\n");

	insertion_sort_f(time_v, dimension);

//	printf("[DEBUG] Vettore tempi ordinato: [" );
//	for(int i=0; i< dimension; i++){
//		printf("%f", time_v[i]);
//	}
//	printf("]\n");

	if(dimension%2 == 1){
		median = time_v[dimension/2];
	}else{
		median = (time_v[dimension/2] + time_v[(dimension/2) -1])/2;
	}
	printf("MEDIANA: %f\n", median);
	return median;
}

void insertion_sort_f(double* vector, int dimension){

	for(int i=1; i< dimension; i++){
		double key = vector[i];
		int j = i-1;
		while(j>= 0 && vector[j]>key){
			vector[j+1] = vector[j];
			j=j-1;
		}
		vector[j+1] = key;
	}

}

void write_file(int dimension, double elapsed_time){
	FILE * fp;
	fp = fopen ("./report.txt","a");

	//Template: Dimension, Elapsed time
	fprintf (fp, "%d,%f\n", dimension, elapsed_time);

	fclose (fp);
}
