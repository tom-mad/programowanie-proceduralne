#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int*a, int*b);
void swap_tab(int*a, int*b, int);
void swap_row(int n, int (*a)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec); 
int main()
{
	int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
	int tab_11[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
	int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};
	int tab_22 [5][2] = {1,1,2,2,3,3,4,4,5,5};
	int **tab_3 = malloc( 6*sizeof(int*));
	for(int i = 0; i < 6; i++)  
		tab_3[i] = malloc(3 * sizeof(int));
	for(int i = 0; i < 6; i++)
  		for(int j = 0; j < 3; j++)
   			tab_3[i][j]  =  rand() % 21;
    int **tab_33= malloc( 6*sizeof(int*));
	tab_33[0] = malloc(6*3 * sizeof(int));
	for(int i = 1; i < 6; i++)  
		tab_33[i] = tab_33[i-1]+3;
	for(int i = 0; i < 6; i++)
  		for(int j = 0; j < 3; j++)
   			tab_33[i][j]  =  rand() % 21;
	printf("------------------------------\nWczytana Tablica tab_1:\n");
	for(int i = 0;i<4;i++)
		wypisz_i(*(tab_1+i),*(tab_1+i)+4);
	printf("------------------------------\nZamiana 1 wiersza z 3(przy użyciu swap_row):\n");
	swap_row(5,tab_1,1,3);
	for(int i = 0;i<4;i++)
		wypisz_i(*(tab_1+i),*(tab_1+i)+4);
	printf("------------------------------\nWczytana Tablica tab_11:\n");
	for(int i = 0;i<4;i++)
		wypisz_i(*(tab_11+i),*(tab_11+i)+4);
	printf("------------------------------\nZamiana 0 wiersza z 3(przy użyciu swap_tab):\n");
	swap_tab(*(tab_11),*(tab_11 + 3),5);
	for(int i = 0;i<4;i++)
		wypisz_i(*(tab_11+i),*(tab_11+i)+4);
	printf("------------------------------\nWczytana Tablica tab_2:\n");
	for(int i = 0;i<5;i++)
		wypisz_i(*(tab_2+i),*(tab_2+i)+1);
	printf("------------------------------\nZamiana 0 wiersza z 2(przy użyciu swap_row):\n");
	swap_row(2,tab_2,0,2);
	for(int i = 0;i<5;i++)
		wypisz_i(*(tab_2+i),*(tab_2+i)+1);
	printf("------------------------------\nWczytana Tablica tab_22:\n");
	for(int i = 0;i < 5;i++)
		wypisz_i(*(tab_22+i),*(tab_22+i)+1);
	printf("------------------------------\nZamiana 1 wiersza z 2(przy użyciu swap_tab):\n");
	swap_tab(*(tab_22+1),*(tab_22 + 2),2);
	for(int i = 0;i < 5;i++)
		wypisz_i(*(tab_22+i),*(tab_22+i)+1);
	printf("------------------------------\nWczytana Tablica tab_3:\n");
	for(int i = 0;i<6;i++)
		wypisz_i(*(tab_3+i),*(tab_3+i)+2);
	printf("------------------------------\nZamiana 1 wiersza z 5:\n");
	swap_tab(*(tab_3+1),*(tab_3 + 5),6);
	for(int i = 0;i<6;i++)
		wypisz_i(*(tab_3+i),*(tab_3+i)+2);
	printf("------------------------------\nWczytana Tablica tab_33:\n");
	for(int i = 0;i<6;i++)
		wypisz_i(*(tab_33+i),*(tab_33+i)+2);
	printf("------------------------------\nZamiana 2 wiersza z 4:\n");
	swap_tab(*(tab_33+2),*(tab_33 + 4),6);
	for(int i = 0;i<6;i++)
		wypisz_i(*(tab_33+i),*(tab_33+i)+2);
	free (tab_3);
	free(tab_33);
	return 0;
}
void swap(int*a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void swap_tab(int*a, int*b, int r)
{
	for(int i = 0;i < r;i++)
		swap(a+i,b+i);
	return;
}

void swap_row(int n, int (*a)[n], int x, int y)
{	
	swap_tab(*(a+x),*(a+y),n);
	return;
}
void wypisz_i (int *poczatek, int *koniec) 
{ 
    while (poczatek <=koniec) 
    	printf ("%4d", *poczatek++); 
    printf ("\n"); return; 
}