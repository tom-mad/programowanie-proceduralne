#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_f (float **matrix,int rows,int columns){
    puts("-----------------------------------\nWypisanie Macierzy:");
    for(int i = 0  ; i < rows ; i++){
        for(int j = 0 ; j<columns ; j++)
            printf("%.2f\t",matrix[i][j]);
        printf ("\n");
    }
    return;
}
float rand_f(float min, float max){
  float r = (float) rand()/RAND_MAX; 
     return  r*(max - min) + min;}

float ** matrix(int rows, int col, FILE * fp){
    int i,j;
    
    
    float ** mat = calloc(rows,sizeof(float*));
    if(mat==NULL)
        return NULL;
    for(i = 0;i<rows;i++)
        *(mat + i) = calloc(col,sizeof(float));

    for(i=0;i<rows;i++)
        for(j=0;j<col;j++)
            if(!feof(fp))
                fread(&mat[i][j],sizeof(float),1,fp);
            else mat[i][j] = 0;
                
  
    return mat;
}

int main(){
    float tab[30];
    int i,x,y;
    
    srand(time(0));
    
    FILE *f_1 = fopen ("dane_1.dat","wb");
    int var;
    printf ("rozmiar = ");
    scanf ("%d", &var);
    
    for (i=0; i<var; i++)
        tab[i]=rand_f(0.0, 40.0);
    fwrite (tab,sizeof(float),var, f_1);
    fclose(f_1);
    
    f_1 = fopen ("dane_1.dat","rb");
    
	x = 3,y = 10;
    float ** mat = matrix(x,y,f_1);
    wypisz_f(mat,x,y);
    free(mat);
    rewind(f_1);
    x = 6,y = 5;
    mat = matrix(x,y,f_1);
    wypisz_f(mat,x,y);
    free(mat);
    fclose(f_1);
    
    return 0;
} 