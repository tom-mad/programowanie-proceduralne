#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10

void zamiana(int *a,int *b);
void odwroc(int *tab,int rozmiar);
void wymien_tablice(int *tab1, int *tab2, int rozmiar);

void main()
{
	int tab1[N],tab2[N];
	srand(time(0));
	for(int i=0;i < N; i++)
   	{
		*(tab1+i)=(10 + rand()%(100-10+1));
    	*(tab2+i)=(10 + rand()%(100-10+1));
	}
	
	printf(";-----------------------------\nZamiana:\n");
	printf("Przed:\n%d\t%d\n",tab1[0],tab2[0]);
	zamiana(tab1,tab2);
	printf("Po:\n%d\t%d\n",tab1[0],tab2[0]);
	
	printf("-----------------------------\nOdwrócenie elementow tablicy:\nPrzed:\n");
	for(int i =0;i<N;i++)
		printf("tab[%d]=%d\n",i,tab1[i]);
	odwroc(tab1,N);
	printf("Po:\n");
	for(int i =0;i<N;i++)
		printf("tab[%d]=%d\n",i,tab1[i]);
	
	printf("-----------------------------\nWymienienie elementow tablicy:\nPrzed:\n");
	for(int i=0;i < N; i++)
	    printf("tab1[%d] = %d\t\ttab2[%d] = %d\n",i,*(tab1+i),i,*(tab2+i));
	wymien_tablice(tab1,tab2,N);
	printf("Po:\n");
	for(int i=0;i < N; i++)
	   	printf("tab1[%d] = %d\t\ttab2[%d] = %d\n",i,*(tab1+i),i,*(tab2+i));
	return;
}
void zamiana(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void odwroc(int *tab,int rozmiar)
{
	for(int i =0;i<rozmiar/2;i++)
	{
		zamiana(tab+i,tab+rozmiar-1-i);
	}	
	return;	
}
void wymien_tablice(int *tab1, int *tab2, int rozmiar)
{

	for(int i=0;i<rozmiar;i++)
	{
			zamiana(tab1+i,tab2+i);
	}
	return;
}	