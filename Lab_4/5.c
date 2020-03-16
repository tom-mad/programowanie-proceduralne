#include <stdio.h>
#include <time.h>
#include<stdlib.h>
double d_rand( double min, double max);
int main(void)
{	
	int n;
	double *tab,*tabD = NULL,*tabU = NULL;
	srand(time(0));
	printf("Rozmiar Tablicy: ");
	scanf("%d",&n);
	tab = (double*)malloc(sizeof(double)*n);
	printf("tab:\n");
	int a = 0, b = 0;
	for(int i = 0;i<n;i++)
	{
		*(tab+i) = d_rand(-1.5,1.5);
		printf("tab[%d] = %4.2f\n",i,*(tab+i));
		if(*(tab+i)>=0)
		{	tabD=(double*)realloc(tabD,sizeof(double)*(a+1));
			*(tabD+a) =*(tab+i);
			a++;
		}
		else
		{
			tabU=(double*)realloc(tabU,sizeof(double)*(b+1));
			*(tabU+b)=*(tab+i);
			b++;
		} 
	}
	printf("Tablica Dodatnich Elementów:\n");
	for(int i = 0;i<a;i++)
		printf("tabD[%d] =%4.2f\n",i,*(tabD+i));
	printf("Tablica Ujemnych Elementów:\n");
	for(int i = 0;i<b;i++)
		printf("tabU[%d] =%4.2f\n",i,*(tabU+i));	
	free(tab);
	free(tabD);
	free(tabU);
	return 0;
}
double d_rand( double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}