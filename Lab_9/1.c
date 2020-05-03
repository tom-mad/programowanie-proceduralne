#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
int i_rand(int min, int max)
{
  return rand() % (max-min+1) + min;
}
int char_cmp(const void * a, const void * b){
    return strcmp((char*)a,(char*)b);
}
void print_tabchars_array(char (*ch_array)[15],int p,int q){
  for(int i = 0; i < p;i++){
    for(int j = 0;j<q;j++)
      printf("%c",ch_array[i][j]);
    printf("\n");
  }
  return;
}
int main()   
{ 
  char tab_char[20][15] ;
  srand(time(0));
  char x[2] ={'A','a'};
  int k;
  for(int i = 0;i<20;i++)
    for(int j = 0;j< 15;j++){
      	k = i_rand(0,1);
      	tab_char[i][j] = x[k] + (rand()%26);
    }
  	puts("*** Wygenerowane Łańcuchy:"); 
  	print_tabchars_array(tab_char, 20,15);
  	for(int i = 0; i<20;i++)
    	qsort(*(tab_char+i),15,sizeof(char),char_cmp);
    puts("*** Posortowany każdy łańcuch:") ;
	print_tabchars_array(tab_char, 20,15);
  	qsort(tab_char,20,15 ,char_cmp);
  	puts("*** Posortowana tablica łańcuchów:") ;
	print_tabchars_array(tab_char, 20,15);
	return 0;
 }
