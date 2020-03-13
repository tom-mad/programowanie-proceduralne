#include<stdio.h>
#include<stdlib.h>
void skresla(int *k,int j,int n)
{
    int z = j+1;
    for(int i=z;i < n-j;i += z)
        *(k+i)= 0;
    return;
}
void main()
{ 
    int n;
    printf("Rozmiar Tablicy: ");
    do
        scanf("%d",&n);
    while((n<1)||(n>100000));
    int *tab = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        *(tab+i)=i+1;
    printf("-----------------------------------------------------\n");
    printf("cos");
    *tab=0;
    for(int i=1;i<n;i++)
    {
        if(*(tab+i)!=0)
            skresla(tab+i,i,n);
    }
    printf("Liczby Pierwsze:\n");
    for(int i=0;i<n;i++)
    {
        if(*(tab+i)!=0)
            printf("%d\t",*(tab+i));
    }
    printf("\n");
    free(tab);
    return;
}
