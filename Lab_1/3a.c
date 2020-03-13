#include<stdio.h>
void zamiana(int *a,int *b);
void main()
{
	int a,b;
	printf("Podaj a = ");
	scanf("%d",&a);
	printf("Podaj b = ");
	scanf("%d",&b);
	printf("Przed:\na = %d\tb = %d\n",a,b);
	zamiana(&a,&b);
	printf("Po zamianie:\na = %d\tb = %d\n",a,b);
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