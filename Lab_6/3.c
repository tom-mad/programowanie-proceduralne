#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void wypisz_i (int *poczatek, int *koniec);
int i_rand(int min, int max)
{
  return rand() % (max-min+1) + min;
}
void proc_1(int * a, int * b,int n);
int main()
{
  	int x;
  	int tab_1[5] = {1,2,3,4,5};
  	printf("------------------------------\ntab_1 przed przesunięciem:\n");
  	wypisz_i (tab_1,tab_1+4);
  	printf("Podaj lp przesunięć:\n");  	
  	scanf("%d",&x);
  	proc_1(tab_1,tab_1+4,x);
  	printf("\ntab_1 po przesunięciu:\n");
  	wypisz_i (tab_1,tab_1+4);
  	

  	int tab_2 [4][2] = {{10,11},{12,13},{14,15},{16,17}};
  	printf("------------------------------\ntab_2 przed przesunięciem:\n");
  	for (int i = 0; i < 4; i++ ) 
  		wypisz_i (*(tab_2+i),*(tab_2 +i)+1);
  	printf("Podaj lp przesunięć:\n");
  	scanf("%d",&x);
  	proc_1(*tab_2,*tab_2+7,x);
	printf("tab_2 po przesunięciu:\n");
  	for (int i = 0; i < 4; i++ ) 
    	wypisz_i (*(tab_2+i),*(tab_2 +i)+1);
  	

  	printf("------------------------------\nTablica Dynamiczna\n");
  	int N,M; //N - ilość wierszy   M- ilość kolumn 
  	printf("Podaj Ilość wierszy i kolumn:");
  	scanf("%d %d",&N,&M);
  	printf("Podaj lp przesunięć:\n");
  	scanf("%d",&x);
  	int** tab;
  	tab = calloc(N,sizeof(int*));
  	*tab = calloc(N*M,sizeof(int));
  	for(int i = 1;i<N;i++)
  	   	*(tab + i) = i*M+*tab;
  	srand(time(0));
  	printf("Wylosowane Wartości:\n");
  	for (int i = 0; i < N; i++ ) 
    	for (int j = 0; j < M; j++ )
        	tab[i][j] = i_rand(0,14); 
  	for (int i = 0; i < N; i++ ) 
    	wypisz_i (*(tab+i),*(tab +i)+M-1);
  	proc_1(&(tab[0][0]),&(tab[N-1][M-1]),x); 
  	printf("Tablica po przesunięciu:\n");
  	for (int i = 0; i < N; i++ ) 
    	wypisz_i (*(tab+i),*(tab +i)+M-1);
    printf("------------------------------\n");

  return 0;
}

void proc_1(int * a,int * b,int n)
{
  for(int j =0; j<n;j++)
  {
    int p = *b,h;
    *b=*a;
    for(int * i = b-1;i >= a;i--)
    {
      h=*i;
      *i = p;
      p= h;
    }
  }
  return;
}
void wypisz_i (int *poczatek, int *koniec) 
{ 
    while (poczatek <=koniec) 
      printf ("%4d", *poczatek++); 
    printf ("\n"); return; 
}