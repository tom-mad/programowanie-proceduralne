#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10 
  
int suma(int const *a, int const *b);

int main(void)
{
	int tab[N],*p;
	time_t czas;   
	srand( (unsigned int)time(&czas) );
    for(p=tab;p  <tab + N; p++)
    {
    	*p=(7 + rand()%(35-7+1));
       	printf("p[%ld] = %d\n",p-tab, *p);
	}

	printf("\n");
    int su = suma(tab, p-1); 
    printf("su=%d\n",su);
    return 0;
} 
int suma (int const *a, int const *b)
{   
    if (a<=b)
   		return (*b + suma(a,b-1));
    else 
    	return 0;
}


    
