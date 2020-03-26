#include<stdio.h>
#include<stdlib.h>
int ** create_table(int *r);
void wypisz_i (int *poczatek, int *koniec);
int main()
{
	int *k;
	*k=0; 
	int **tab = create_table(k);
	printf("Stworzona tablica:\n");
	for(int i = 0;i < *k;i++)
		wypisz_i(*(tab+i),*(tab+i)+4);
	free(tab);
	return 0;
}
void wypisz_i (int *poczatek, int *koniec) 
{
	while (poczatek < koniec)
		printf ("%2d\t", *poczatek++);
	printf ("\n");
	return;
}
int ** create_table(int *r)
{
	int ** TAB = NULL,n,a=-1,b=0;

	do
	{
		printf("Podaj liczbę(0 kończy tworzenie tablicy):");
		scanf("%d",&n);
		if(*r==0||b==4)
		{
			*r+=1;
			TAB = (int**)realloc(TAB,*r*sizeof(int*));
			*TAB = (int*)realloc(*TAB,*r*4*sizeof(int));
			for(int i = 1;i<*r;i++)
				*(TAB + i) = i*4+*TAB;
			a++;
			b=0;
		}
		*(*(TAB+a)+b) = n;
		b++;
	}
	while(n!=0);
	while(b!=4)
	{
		*(*(TAB+a)+b) = 0;
		b++;	
	}
	return TAB;
}