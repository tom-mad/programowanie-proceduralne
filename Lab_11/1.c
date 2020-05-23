#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void print_text_double(char *name){
  int x;
  FILE * p = fopen(name,"r");
  puts("\n--------------------------------------\nWypisanie pliku tekstowego:");
  x = getc( p ); 
    while( x != EOF )                  
    {
        printf( "%c", x );             
        x = getc( p );
    } 
  
  fclose(p);
}
void print_bin_double(char *name){
  FILE * p = fopen(name,"rb");
  fseek(p, 0, SEEK_END);
  long size = ftell(p);
  rewind (p);
  puts("\n--------------------------------------\nWypisanie pliku binarnego:");
  double * tab = malloc (size);
  fread (tab,1,size,p);

  for(int i=0; i < size/sizeof(double) ; i++)
    printf("%lf\n",tab[i]);  
    free(tab);
  fclose(p);

}

int main(int argc,char *argv[]){
    
    if(argc!=3){
        printf("Podaj Nazwe pliku przy wywolaniu");
        return 0;
    }
    int size_d,i;
    double *tab_d;
    FILE *file_1,*file_2;
    
    do{
    puts("--------------------------------------\nPodaj Rozmiar Tablicy Liczb Rzeczywistych z zakresu <1,+infinity)");
        scanf("%d",&size_d);
    }while(size_d<=0);
    
    srand(time(NULL));
    tab_d  = calloc(size_d,sizeof(double));
    
    puts("--------------------------------------\nWylosowana Tablica:\n");
    for(i=0; i<size_d ; i++){
        tab_d[i] = (rand()%(201)-100)/(double)5;
        printf("%.2lf\t",tab_d[i]);
    }
    puts("\n--------------------------------------\n");
    file_2 = fopen ( argv[2] , "w") ;

    if (file_2 == NULL){
        printf("Blad\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<size_d ; i++){
        fprintf(file_2,"%lf\n",tab_d[i]);
    }
    fclose(file_2);
    print_text_double(argv[2]);
  
    
    file_1 = fopen ( argv[1] , "wb") ;
    if (file_1 == NULL){
        printf("Blad\n");
        exit(EXIT_FAILURE);
    }
    
    fwrite(tab_d,sizeof(double),size_d,file_1); 
    
    fclose(file_1);
    print_bin_double(argv[1])  ; 
    
 
  file_2 = fopen ( argv [2] , "r");
  fseek(file_2, 0, SEEK_END);
  printf("\nPlik tekstowy = %ld bytes\n", ftell(file_2));
  rewind (file_2);
  puts("\n--------------------------------------\nStworzona Tablica na podstawie pliku tekstowego:");
  double * tab_f2 = NULL;
  i=0;
  while(!feof(file_2)){
    i++;
    tab_f2 = realloc(tab_f2,i*sizeof(double));
    fscanf ( file_2, "%lf", tab_f2+i-1 );
  }
  fclose(file_2);
  
  for(i=0; i < size_d ; i++)
    printf("%.2lf\t",tab_f2[i]); 
  
  
  file_1 = fopen ( argv [1] , "rb+");
  fseek(file_1, 0, SEEK_END);
  long size_file1 = ftell(file_1);
  printf("\nPlik Binarny = %ld bytes\n",size_file1 );
  rewind (file_1);
  puts("\n--------------------------------------\nStworzona Tablica na podstawie pliku binarnego:");
  double * tab_f1 = malloc (size_file1);
  fread (tab_f1,1,size_file1,file_1);

  for(i=0; i < size_file1/sizeof(double) ; i++)
    printf("%.2lf\t",tab_f1[i]);  
  rewind (file_1);
  
  puts("\n\n\n\nZmienienie Pliku Binarnego:");
  double nul = 0.0;

  for(i=0;i < size_file1/sizeof(double);i+=5){
    fwrite(&nul, sizeof(double), 1, file_1);
    fseek(file_1,sizeof(double)*4,SEEK_CUR);
  }
  rewind (file_1);
  fread (tab_f1,1,size_file1,file_1);

  fclose(file_1);
  print_bin_double(argv[1])  ; 

  free(tab_f1);
  free(tab_f2);
  free(tab_d);
  return 0;
}