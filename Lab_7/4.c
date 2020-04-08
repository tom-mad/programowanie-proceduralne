#include<stdio.h>
int add2(int *a,int *b);
int comp2(int *a,int *b);
int add2_or_comp2(int *k,int *l,int (*funkcja)(int*,int*));
int main(void)
{
	int i,j;
	printf("Podaj Liczby:");
	scanf("%d%d",&i,&j);
	printf("-----------------------------------------\nZ wykorzystaniem Funkcji add2_or_comp2:\n");
	printf("Suma:%8.d\nRóżnica:%5.d\n",add2_or_comp2(&i,&j,add2),add2_or_comp2(&i,&j,comp2));
	return 0;
}
int add2(int *a,int *b)
{
	return *a + *b;
}
int comp2(int *a,int *b)
{
	return *a-*b;
}
int add2_or_comp2(int *k,int *l,int (*funkcja)(int*,int*))
{
	return funkcja(k,l);
}
