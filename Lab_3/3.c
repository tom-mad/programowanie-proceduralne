#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
float f_rand(double min, double max);
void wypisz_d (float *poczatek, float *koniec);
void wypelnij(float a[][6],int b);
void main()
{   
    float  A_1[8][6],A_2[10][6];
    wypelnij(A_1,8);
    printf("Tablica A_1:\n");
    for(int i=0;i<6;i++)
    {
        wypisz_d(*(A_1+i), *(A_1+i)+7);
    }
    wypelnij(A_2,10);
    printf("Tablica A_2:\n");
    for(int i=0;i<6;i++)
    {
        wypisz_d(*(A_2+i), *(A_2+i)+9);
    }
    return;
}
void wypisz_d (float *poczatek, float *koniec) 
{ 
    while (poczatek <= koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}
void wypelnij(float a[][6],int b)
{
	float n;
	printf("Podaj Liczbę: ");
	scanf("%f",&n);
	for(float * i = &a[0][0];i<&a[b-1][6];i++)
	{
		n+=0.4;
		*i = n;
	} 
    return;
}
float f_rand(double min, double max)
{
	float r = (float) rand()/RAND_MAX;
	return r*(max-min) + min;
}
