#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
float suma (float t[], int n);
float f_rand(float min, float max);
void main()

{
	float tab[N];
	int rozmiar = sizeof(tab)/sizeof(int);
	time_t czas;   
	srand( (unsigned int)time(&czas) );
	printf("Przed:\n");
   	for(int i=0;i < rozmiar; i++)
    {
  		*(tab+i)=f_rand(-100,100);
       	printf("tab[%d] = %f\n",i,*(tab+i));		
    }
    printf("Suma = %f",suma(tab,rozmiar));
	return;
}
float f_rand(float min, float max)
{
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
float suma (float *t, int n)
{
	float s=0;
	for(int i=0;i<n;i++)
	{
		s+=*(t+i);
	}
	return s;
}