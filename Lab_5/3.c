#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_tab(int a[][4], int x);
void wypisz_i (int *poczatek, int *koniec);
int ** mn_tab_1(int A[][3],int B[][4],int n);
int main()
{
	int t_A [2][3] = {1,2,3,4,5,6};
	int t_B [3][4] = {1,1,1,1,1,1,1,1,1,1,1,1};
	int ** t_C = mn_tab_1 (t_A, t_B, 2);
	return 0;
	
}
int ** mn_tab_1(int A[][3],int B[][4],int n)
{
	printf("%ld\t%ld",sizeof(A[3])/sizeof(int),sizeof(B[4])/sizeof(int));
	return NULL;
}
void wypisz_i (int *poczatek, int *koniec) 
{
	while (poczatek <= koniec)
		printf ("%4d", *poczatek++);
	printf ("\n");
	return;
}
void print_tab(int a[][4], int x)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < 4; j++)
			printf ("%3d", a[i][j]);
		printf ("\n");
	}
return;
}