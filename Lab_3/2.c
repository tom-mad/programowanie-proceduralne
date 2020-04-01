#include <stdio.h>
void wypisz_d (double *poczatek, double *koniec);
double  suma (double **tab,int nr,int lenght);
double * find_tab(double **t,int d, int n);
void swap_new(double * a,double *b, int u);
void find_tab_1(double **t1, int y,int x);
int main()
{
	double T_1[4] = {1.0,3.0, 2.0,1.5};
	double T_2[4] = {1.8, 2.0, 1.2, 3.8};
	double T_3[4] = {5.6, 1.0, 3.3, 3.3};
	double T_4[4] = {1.1, 2.1, -6.5, 1.7};
	double T_5[4] = {6.7, 7.8, 9.1, 1.0};
	double * TAB[5]={T_1,T_2,T_3,T_4,T_5};
	printf ("Pierwsze Wypisanie:\n");
  for (int i = 0; i<sizeof(TAB)/sizeof(double*); i++)
  {
    for (int j = 0; j<4; j++)
	    printf("%8.2f", TAB[i][j]);
    printf ("\n");
  }
  double **TABLICA = TAB;
  printf ("Drugie Wypisanie:\n");
  for(int i=0;i < sizeof(TAB)/sizeof(double*);i++)
  {
    wypisz_d(*(TABLICA+i), *(TABLICA+i)+3);
  }
  for(int i=0;i < sizeof(TAB)/sizeof(double*);i++)
  {
    printf("Suma elementów w wierszu o indeksie[%d]=\t%.2f\n",i,suma (TAB, i, 4) );
  }
  double *p = find_tab(TAB,0, sizeof(TAB)/sizeof(double*));
  printf("Adres do tablicy z najmniejszą sumą=\t%p\n",p);
  printf ("Elementy tej tablicy:\n"); 
  wypisz_d(p, p+4);
  find_tab_1(TAB, sizeof(TAB)/sizeof(double*),4);
  printf ("Posortowana Tablica:\n");
  for(int i=0;i < sizeof(TAB)/sizeof(double*);i++)
  {
    wypisz_d(*(TABLICA+i), *(TABLICA+i)+3);
  }
  return  0;
}
void wypisz_d (double *poczatek, double *koniec) 
{ 
  	while (poczatek <= koniec) 
    printf ("%8.2f", *poczatek++); 
  	printf ("\n");    
  	return;
}
double suma (double **tab,int nr,int lenght)
{
  double s = 0 ;
  for(int j = 0;j<lenght;j++)
  {
    s+=*(*(tab+nr)+j);
  }
  return s;
}
double * find_tab(double **t,int d, int n)
{
  int l = d;
  int m = suma (t, l, 4);
  for(int i = d+1;i<n;i++)
  {
    if(m>suma(t,i,4))
    {
      l = i;
      m = suma(t,l,4);
    }
  }
  return *(t+l);
}
void swap_new(double * a,double *b,int u)
{
  double f;
  for(int i=0;i<u;i++)
  {
    f=*(a+i);
    *(a+i) = *(b+i);
    *(b+i) = f;
  }
  return;
}
void find_tab_1(double **t1, int y,int x)
{
  for(int i = 0; i < y ; i++)
  {  
    double *k =find_tab(t1,i,y);
    if(k!=*(t1+i))
      swap_new(k,*(t1+i),x);
  }
  return;
}