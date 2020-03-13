#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
void zamiana(int *a,int *b);
void wymien_tablice(int *tab1, int *tab2, int rozmiar);
void main()
{
	int tab1[N],tab2[N];
	int rozmiar=sizeof(tab1)/sizeof(int);
	if(rozmiar==sizeof(tab2)/sizeof(int))
	{
		time_t czas;   
		srand( (unsigned int)time(&czas) );
		printf("Przed:\n");
    	for(int i=0;i < rozmiar; i++)
   	 {
    		*(tab1+i)=(10 + rand()%(100-10+1));
    		*(tab2+i)=(10 + rand()%(100-10+1));
	       	printf("tab1[%d] = %d\t\ttab2[%d] = %d\n",i,*(tab1+i),i,*(tab2+i));
		}
		printf("\n\nPo:\n");
		
		{
			wymien_tablice(tab1,tab2,rozmiar);
			for(int i=0;i < rozmiar; i++)
   				printf("tab1[%d] = %d\t\ttab2[%d] = %d\n",i,*(tab1+i),i,*(tab2+i));
   		}
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
void wymien_tablice(int *tab1, int *tab2, int rozmiar)
{

	for(int i=0;i<rozmiar;i++)
	{
			zamiana(tab1+i,tab2+i);
	}
	return;
}	