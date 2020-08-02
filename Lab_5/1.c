#include<stdio.h>
#include<stdlib.h>
#define rows 2
#define columns 3

void wypisz_i (int *poczatek, int *koniec) 
{
	while (poczatek < koniec)
	printf ("%4d", *poczatek++);
	printf ("\n");
	return;
}
int main()
{

	//struktura 1
	int ** array_1 = (int**)calloc(rows,sizeof(int*));
	for(int i = 0;i<rows;i++)
		*(array_1 + i) = (int*)calloc(columns,sizeof(int));
	for(int i = 0; i<rows;i++)
	{
		wypisz_i (*(array_1+i), *(array_1+i)+columns); 
		printf("\n");
	}
	//struktura 2
	int ** array_2 = (int**)calloc(rows,sizeof(int*));
	*array_2 = (int*)calloc(rows*columns,sizeof(int));
	for(int i = 1;i<rows;i++)
		*(array_2 + i) = i*columns+*array_2;
	
	//struktura 3, int (* array_3)[columns]
	int (* array_3)[columns] = calloc(rows,sizeof(*array_3));
	free(array_1);
	free(array_2);
	free(array_3);
	return 0;
}