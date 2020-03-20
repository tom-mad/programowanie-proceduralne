#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void przesun(char * a, char * b);
int main()
{
  int N,M; //N - ilość wierszy   M- ilość kolumn 
  printf("Podaj Ilość wierszy i kolumn:");
  scanf("%d %d",&N,&M);
  char ** tab;
  tab = malloc( N * sizeof( char * ) );
  for (int i = 0; i < N; i++ ) 
  { 
    tab[i] = malloc( M * sizeof( char ) ); 
  }
  srand(time(0));
  printf("Wylosowane Wartości:\n");
  for (int i = 0; i < N; i++ ) 
    { 
      for (int j = 0; j < M; j++ )
      { 
        tab[i][j] = 'a' + (rand()%26);
        printf(" %c  ", tab[i][j]);
      } 
        printf("\n"); 
    }
 printf("Tablica po przesunięciu:\n");
  for (int i = 0; i < N; i++ ) 
    { 
      for (int j = 0; j < M; j++ )
      { 
        printf(" %c  ", tab[i][j]);
      } 
        printf("\n"); 
    }
  przesun(&(tab[0][0]),&(tab[N-1][M-1])); 
  printf("Tablica po przesunięciu:\n");
  for (int i = 0; i < N; i++ ) 
    { 
      for (int j = 0; j < M; j++ )
      { 
        printf(" %c  ", tab[i][j]);
      } 
        printf("\n"); 
    }


  return 0;
}

void przesun(char * a,char * b)
{
  char p = *a,h;
  *a=*b;
  for(char * i = a+1;i<=b;i++)
    {
      h=*i;
      *i = p;
      p= h;
    }

  return;
}