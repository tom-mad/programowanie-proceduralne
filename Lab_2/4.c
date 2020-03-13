#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10 
int Partition(float *A,int p,int r);
float f_rand(float min, float max);
void Quicksort(float *A,int p,int r);
void swap(float*a, float*b);
void main(void)
{
	float tab[N];
	time_t czas;   
	srand( (unsigned int)time(&czas) );
	printf("Przed:\n");
    for(float *i=tab;i<tab+N;i++)
    {
    	*i = f_rand(-1.50,5.50);
    	printf("tab[%ld]\t=\t%f\n",i-tab,*i);
	}
	Quicksort(tab,0,N-1);					//Podajemy Wskaźnik na 1 element, indeks 1 i ostatniego elementu
	printf("Po:\n");
   for(float *i=tab;i<tab+N;i++)
    {
    	printf("tab[%ld]\t=\t%f\n",i-tab,*i);
	}
	return;
}
float f_rand(float min, float max)
{
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
void Quicksort(float *A,int l,int p)
{
	if(l < p)						//sprawdzamy czy indeks 1 jest mniejszy od 2
	{	
    	int q = Partition(A, l, p);
    	Quicksort(A,l,q-1);
    	Quicksort(A,q+1,p);
	}
	return; 
}   
int Partition(float *A,int l,int p)
{
	float x = *(A+p); 	
    int i = l;
    for(int j = l; j<=p;j++)
    {
    	if(*(A+j)<x)
    	{
    		swap(A+i,A+j);
    		i = i+1;
    	}
    }
    swap(A+i,A+p);
    return i;
}
void swap(float*a, float*b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}