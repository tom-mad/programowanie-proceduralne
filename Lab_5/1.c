#include<stdio.h>
#include<stdlib.h>
#define rows 10
#define cloumns 10
int main()
{
	int ** array_1,**array_2;
	printf("Podaj ilość Wierszy i Kolumn: ");
	scanf("%d%d",&rows,&columns);
	//struktura 1
	array_1 = (int**)calloc(rows,sizeof(int*));
	for(int i = 0;i<rows;i++)
		*(array_1 + i) = (int*)calloc(columns,sizeof(int));
	//struktura 2
	array_2 = (int**)calloc(rows,sizeof(int*));
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