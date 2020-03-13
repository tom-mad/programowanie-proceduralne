#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
void zamiana(int *a,int *b);
void odwroc(int *tab,int rozmiar);
void main()
{
	int tab[N];
	int rozmiar= sizeof(tab)/sizeof(int);
	time_t czas;   
	srand( (unsigned int)time(&czas) );
	printf("Przed:\n");
    for(int p=0;p < rozmiar;p++)
    {
    	*(tab+p)=(0 + rand()%(100+1));
       	printf("tab[%d] = %d\n",p,*(tab+p));
	}
	odwroc(tab,rozmiar);
	printf("\n\nPo:\n");
    for(int p=0;p < rozmiar; p++)
    {
       	printf("tab[%d] = %d\n",p,*(tab+p));
	}
	return;
}
void zamiana(int *a,int *b)
{
	int k;
	k=*a;
	*a=*b;
	*b=k;
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