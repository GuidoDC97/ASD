#include <stdio.h>
#include "vector.h"
#include "insertion_sort.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

double execute_sorting(int dimension);
void write_file(int dimension, double elapsed_time);
double extract_median_time(double* time_v, int dimension);

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
	int dim_rep = step;
	while(dim_rep <= dim){
		printf("Sorting %d elements vector %d times.\n",dim_rep, trials);

		for(int i=0; i<trials; i++){
			printf("\nRepetition %d\n",i+1);
			time_v[i] = execute_sorting(dim_rep);
			//printf("time_v[%d]: %f\n",i, time_v[i]);

		}
		median_time = extract_median_time(time_v, trials);
		write_file(dim_rep, median_time);
		dim_rep += step;
	}

	system("pause");
	return 0;
}


void write_file(int dimension, double elapsed_time){
	FILE * fp;
	fp = fopen ("./report.txt","a");

	//Template: Dimension, Elapsed time
	fprintf (fp, "%d,%f\n", dimension, elapsed_time);

	fclose (fp);
}

double execute_sorting(int dimension){
	vector v;
	create_rev_sorted_vector(&v, dimension);
	//print_vector(&v);

	printf("\nSORTING...\n\n");

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	insertion_sort(&v);
	clock_gettime(CLOCK_MONOTONIC, &end);

	double elapsed_time;
	elapsed_time = (end.tv_sec - start.tv_sec) * 1e9;
	elapsed_time = (elapsed_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
	printf("Elapsed time: %fs.\n", elapsed_time);
	//print_vector(&v);

	destroy_vector(&v);
	return elapsed_time;
}

double extract_median_time(double* time_v, int dimension){
	double median = 0;

//	printf("\n[DEBUG] Vettore tempi NON ordinato: [" );
//		for(int i=0; i< dimension; i++){
//			printf("%f, ", time_v[i]);
//		}
//	printf("]\n");

	insertion_sort_f(time_v, dimension);

/*	printf("\n[DEBUG] Vettore tempi ordinato: [" );
	for(int i=0; i< dimension; i++){
		printf("%f, ", time_v[i]);
	}
	printf("]\n");*/

	if(dimension%2 == 1){
		median = time_v[dimension/2];
	}else{
		median = (time_v[dimension/2] + time_v[(dimension/2) -1])/2;
	}

	printf("MEDIANA: %f\n", median);

	return median;
}
