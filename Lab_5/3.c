#include<stdio.h>
#include<stdlib.h>
void print_tab(int a[][4], int x);
void wypisz_i (int *poczatek, int *koniec);
int ** mn_tab_1(int A[][3],int B[][4],int n);
int main()
{
	int t_A [2][3] = {1,2,3,4,5,6};
	int t_B [3][4] = {1,1,1,1,1,1,1,1,1,1,1,1};
	int (*t_C)[4] = mn_tab_1 (t_A, t_B, 2);
	return 0;
	
}
int ** mn_tab_1(int A[][3],int B[][4],int n)
{
	int (* C)[4] = calloc(n,sizeof(*C));
	int a=0,b=0;
	while(a!=2)
	{
		*(*(C+a)+b) = ;
		b++;
		if(b==4)
		{
			a++;
			b=0;
		}
	}
	printf("%ld\t",sizeof(C));

	return C; 
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
int ** mn_tab_1(int A[][3],int B[][4],int n);