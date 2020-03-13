#include<stdio.h>
int * find_max_wsk (int *a, int *b);
void sort (int *tab, int n);
void swap(int*a, int*b);
void main()
{ 
	int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
	int rozmiar = sizeof(tab_A)/sizeof(int);
	int *ost = tab_A+rozmiar-1;
	printf("Wskaźnik na element maksymalny tablicy:\n%p\n",find_max_wsk(tab_A,ost));
	sort(tab_A,9);
	sort(tab_A+9,rozmiar-9);
	
	for(int *i=tab_A;i<tab_A+rozmiar;i++)
	{
		printf("tab_A[%ld] = %d\twskaźnik tab_A[%ld] = %p\n",i-tab_A,*i,i-tab_A,i);
	}
    return;
}
void swap(int*a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int * find_max_wsk (int *a, int *b)
{
	int *max=a;
	for(int *i=a+1;i<=b;i++)
	{
		if(*i>*max)
			max=i;
	}
	return max;
}
void sort (int *tab, int n)
{
	for(int *i = tab;i<tab+n-1;i++)
	{
		swap(find_max_wsk(i,tab+n-1),i);
	}
	return;
}