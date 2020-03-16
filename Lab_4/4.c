#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	float *C = NULL;
	float A[] = {1.0,1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9};
	float B[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0};
	a= sizeof(A)/sizeof(float);
	b=sizeof(B)/sizeof(float);
	printf("Tablica A:\n");
	for(int i = 0;i<a;i++)
		printf("A[%d] =%6.2f\n",i,*(A+i));
	printf("Tablica B:\n");
	for(int i = 0;i<b;i++)
		printf("B[%d] =%6.2f\n",i,*(B+i));
	int r=1;
	C=(float*)realloc(C,sizeof(float)*(r));
	*C = *A;
	for(int i = 1;i<a;i++)
	{
		if(*(C+r-1)!=*(A+i))
		{
			r++;
			C=(float*)realloc(C,sizeof(float)*(i+1));
			*(C+r-1) = *(A+i);
		} 
	}
	if(*(B+b-1)>*(C+r-1))
	{
		r++;
		C=(float*)realloc(C,sizeof(float)*r);
		*(C+r-1)=*(B+b-1);
		b--;
	}
	for(int i = 0;i < b;i++)
	{
		float x = *(B + i);
		for(int c = 0;c<r;c++)
		{
			if(*(C+c)>=x)
				if(x!=*(C+c))
				{	
					r++;
					float k;
					C=(float*)realloc(C,sizeof(float)*r);
					for(int d = c;d<r;d++)
					{
						k = *(C+d);
						*(C+d) = x;
						x = k;
					}
					break;	
				}
				else break;
		}
	}

	printf("Wynikowa Tablica C:\n");
	for(int i = 0;i<r;i++)
		printf("tabU[%d] =%6.2f\n",i,*(C+i));
	free(C);
	return 0;
}