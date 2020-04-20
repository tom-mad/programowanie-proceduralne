#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define ROZMIAR 81        //maksymalna dlugość łańcuchów
#define GRAN 20           // maksymalna liczba łańcuchów
void sortlan(char *lan[], int num);  //procedura sortująca łancuchy  
int main(void){
  char dane[GRAN][ROZMIAR];    //tablica przechowujaca łańcuchy nie dłuzsze niz ROZMIAR znakow nie wiecej niz GRAN
  char **wsklan = NULL;        //wskaźnik na tablicę wskaźników - rozmiar zależny od ilości wczytanych łańcuchów             
  int licz = 0;                //licznik danych wejsciowych     
  int k;                        
  printf("Podaj maksymalnie %d wierszy \n",GRAN);
  printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
  while (licz < GRAN && fgets(dane[licz],ROZMIAR,stdin) != NULL && dane[licz][0] != '\n'){  
     wsklan = realloc(wsklan,(licz+1)*sizeof(char*));
    *(wsklan+licz) = dane[licz];    //ustaw wskaźnik z tablicy wsklan na wczytany łańcuch     
     licz++;
  }
  puts("\n Wczytano:\n");
  for (k = 0; k < licz; k++)
     puts(*(wsklan+k)) ;   // z użyciem identyfikataora wsklan
  sortlan(wsklan,licz); // wywłoanie procedury sortującej 
  puts("\n Oto uporzadkowana lista:\n"); 
    for (k = 0; k < licz; k++) 
      puts(*(dane+k));
  free(wsklan);  // z użyciem identyfikataora dane
  return 0; 
} 
// procedura sortująca  
void sortlan(char *lan[], int num){ 
  int i, j;
  char temp[ROZMIAR];
  for (i = 0 ; i < num-1;i++)
    for (j = i+1; j < num;j++ )
      if (strcmp(*(lan+i),*(lan+j)) > 0){ 
        strcpy(temp,*(lan+i));
        strcpy(*(lan+i),*(lan+j));
        strcpy(*(lan+j),temp);
      }
} 