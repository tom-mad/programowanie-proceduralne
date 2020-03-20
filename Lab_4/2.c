#include <stdio.h> //kompilacja  gcc 2.c -lm
#include<stdlib.h>
#include <time.h>
#include<math.h>
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
	*k=(int)floor(*a * *b);
	return k;
}
double d_rand(double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}