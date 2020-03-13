#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 5
void swap(int *a, int *b);
int suma (int *tab, int ile);
int rand_int (int a, int b);
void wypisz_i (int *poczatek, int *koniec);
void main()
{
    int abc[x][x];
    time_t czas;
    srand( (unsigned int)time(&czas) );
    for(int i=0; i < x; i++)
    {
        for(int a=0; a<x; a++)
        {
            abc[i][a]=rand_int(-10,10);
        }
    }
    printf("Macierz :\n");
    for(int i=0;i<x;i++)
    {
        wypisz_i(*(abc+i), *(abc+i)+x-1);
        
    }
    printf("\n-----------------------------------------------------\n");
    int suma_abc[x];
    printf("\nSuma Kolejnych Wierszy : ");
    for(int i=0; i<x; i++)
    {
        suma_abc[i]=suma(&abc[i][0], x);
        printf("%d\t", suma_abc[i]);
    }
    printf("\n-----------------------------------------------------\n");
    int suma_all = suma (*abc, sizeof(abc)/ sizeof(int));
    printf("\nSuma = %d", suma_all);
    for(int *p=*abc;p<*abc+x*x;p+=x+1)
    {       
         for(int *i=p,*a=p;i<*abc+x*x;i+=x,a++)
        {
            swap(a,i);
        }
    }
    printf("\n-----------------------------------------------------\n");
    printf("\nTransponowana:\n");
    for(int i=0;i<x;i++)
    {
        wypisz_i(*(abc+i), *(abc+i)+x-1);
    }
    printf("\n-----------------------------------------------------\n");    
    printf("\nSuma Kolejnych Kolumn : ");
    int suma_kolumn[x];
    for(int i=0; i<x; i++)
    {
        suma_kolumn[i]=suma(&abc[i][0], x);
        printf("%d ", suma_kolumn[i]);
    }
    printf("\n-----------------------------------------------------\n");
    printf("\nSuma Wyliczona Z sum kolumn: ");
    int s=0;
    for(int i=0; i<5; i++)
    {
        s=s+ suma_kolumn[i];
    }
    printf("%d ", s);
    printf("\n-----------------------------------------------------\n");
    printf("Liczby Na Przekątnej i Pod\n");
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<x; j++)
        {
            if(j<=i)
            printf("%d\t", abc[i][j]);
        }
        printf("\n");
    }
    printf("\n-----------------------------------------------------\n");
    return;
}
void swap(int *a, int *b)
{
    int k =*a;
    *a=*b;
    *b=k;
    return;
}
int suma (int *tab, int ile)
{
    int s=0;
    int *p=tab;
    while(p<tab+ile)
    {
        s=s+*p;
        p++;
    }
    return s;
}
int rand_int (int a, int b)
{
    return (a + rand()%(b-a+1));
}
void wypisz_i (int *poczatek, int *koniec) 
{ 
    while (poczatek <= koniec) 
        printf ("%4d", *poczatek++);   
    printf ("\n");    
    return;
}