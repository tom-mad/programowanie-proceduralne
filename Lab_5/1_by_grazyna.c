#include<stdio.h>
#include<stdlib.h>
#define rows 4
#define columns 5

void wypisz_i (int *poczatek, int *koniec) {
  while (poczatek < koniec)  
    printf ("%4d", *poczatek++);    
  printf ("\n");     
  return;
}
int main(){
    int i;

//zad1.1
int **array1 = calloc(rows, sizeof(int*));
if (array1==NULL) return 1;
    
for(i = 0; i < rows; i++){
   array1[i] = calloc(columns, sizeof(int));
   if (array1[i]==NULL) return 1;
}
  for (i = 0;i < rows; i++)
    wypisz_i (array1[i], array1[i]+columns)    ;
 //zwalnianie pamieci
 for (i = 0;i < rows; i++)
   free (array1[i]) ;
 free (array1);    
printf ("\n----------------------\n");    

//zad1.2
int **array2 = calloc(rows, sizeof(int*));
if (array2==NULL) return 1;
    
array2[0] = calloc(columns*rows, sizeof(int));
if (array2[0]==NULL) return 1;

for(i = 1; i < rows; i++){
   array2[i]  =  array2[i-1]+columns;
   }
  for (i = 0;i < rows; i++)
    wypisz_i (array2[i], array2[i]+columns)    ;


free (array2[0]) ;
 free (array2);
 printf ("\n----------------------\n");    

//zad1.3
    
int (*array3)[columns] = calloc(rows*columns, sizeof(int));    
if (array3==NULL) return 1;    
for (i = 0;i < rows; i++)
    wypisz_i (array3[i], array3[i]+columns)    ;    

free (array3);
}
