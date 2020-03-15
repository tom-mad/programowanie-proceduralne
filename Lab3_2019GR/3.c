#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{	
	int a;
	int *pas;
	printf("Podaj Wysokość Trójkąta Pascala: ");
	scanf("%d",&a);
	pas = malloc(sizeof(int)*1);
	*pas = 1; 
	for(int i=1;i<=a;i++)
	{
		pas = realloc(pas, i*sizeof(int));
		*(pas+i-1)=1;
		if(i>2)
		{
			int x,y,l=*(pas);
			for(y = 1;y<i-1;y++)
			{
				x=*(pas+y);
				*(pas+y)=*(pas+y)+l;
				l=x;
			}
		}
		printf(" %4.d.",i);
		for(int z = 0;z<a-i+10;z++)
			printf(" ");
		for(int p =0;p<i;p++)
			printf("%2.d ",*(pas+p));
		printf("\n");
	}
	free(pas);
	return 0;
}