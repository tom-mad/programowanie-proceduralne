#include <stdio.h>
#include <time.h>
#include<stdlib.h>
double d_rand( double min, double max);
int main()
{	
	int a,b;
	double *tab,*iter;
	srand(time(0));
	printf("Rozmiar Tablicy: ");
	scanf("%d",&a);
	tab = malloc(sizeof(double)*a);
	for(double *i = tab;i<tab+a;i++)
		*i = d_rand(23.0,34.0);
	iter = tab;
	for(double *i = iter;i<iter+a;i++)
		printf("tab[%ld]=%2.2lf\n",i-iter,*i);
	printf("\n");
	printf("Zmień Rozmiar Tablicy: ");
	scanf("%d",&b);
	tab = realloc(tab, b*sizeof(double));
	if(b>a)
	{
	for(double *i = tab+a;i<tab+b;i++)
		*i = d_rand(-20.0,-5.0);
	}
	for(double *i = iter;i<iter+b;i++)
		printf("tab[%ld]=%2.2lf\n",i-iter,*i);
	printf("\n");
	
	free(tab);
		
	return 0;
}
double d_rand( double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}