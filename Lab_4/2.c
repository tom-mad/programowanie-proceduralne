#include <stdio.h>
#include<stdlib.h>
#include <time.h>
double d_rand(double min, double max);
int * floor1(double * a ,double * b);
int main(void)
{
	double *lp = NULL;
	srand(time(0));
	for(int i = 0;i<2;i++)
	{
		lp = (double*)realloc(lp, (i+1)*sizeof(double));
		*(lp+i) =  d_rand(0, 100);
		printf("%d Liczba = %f\n",i+1,*(lp+i));
	}
	int *w =floor1(lp,lp+1); 	
	printf("Obliczona Lp= %d \tAdres=%p\n ",*w,w);
	free(lp);
	free(w);
	return 0;
}

int *floor1(double * a ,double * b)
{
	int *k;
	k = (int*)malloc(sizeof(int));
	int n = *a * *b;
	*k = n;
	return k;
}
double d_rand(double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}