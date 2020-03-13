#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define N 10
float suma (float *t, int n,float*h,float*l);
float f_rand(float min, float max);
void main()
{
	float tab[N];
	float max,min,srednia,sum;
	int rozmiar = sizeof(tab)/sizeof(int);
	time_t czas;   
	srand( (unsigned int)time(&czas) );
	printf("Tablica:\n");
   	for(int i=0;i < rozmiar; i++)
    {
  		*(tab+i)=f_rand(-100,100);
       	printf("tab[%d] = %f\n",i,*(tab+i));		
    }
    sum=suma(tab,rozmiar,&max,&min);
    srednia = sum / rozmiar;
    printf("Suma = %f\tSrednia = %f\tMaksymalny Element = %f\tMinimalny Element = %f\n",sum,srednia,max,min);
	return;
}
float f_rand(float min, float max)
{
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
float suma (float *t, int n,float*h,float*l)
{
	float s=*t;
	*h=*t;
	*l=*t;
	for(int i=1;i<n;i++)
	{
		s+=*(t+i);
		if(*(t+i)>*h)
			*h=*(t+i);
		if(*(t+i)<*l)
			*l=*(t+i);
	}
	return s;
}