#include<stdio.h>

void file_copy(FILE * f_in,FILE * f_out){
    char chr;
    while((chr = fgetc(f_in)) != EOF)
        fputc(chr,f_out);
}
int file_cmp(char * in, char * out){

    FILE *f1 = fopen(in, "r");
    FILE *f2 = fopen(out, "r");
    char c1, c2;
    do
    {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 != c2)
            return -1;
    } while (c1 != EOF && c2 != EOF);
    if (c1 == EOF && c2 == EOF)
        return 0;
    else
        return -1;
    fclose(f1);
    fclose(f2);
}
int main(){
    FILE *fi1, *fi2,*fi3,*fi4,*fi5,*fi6;

    int i;
    char plik1[] = "tekst_1.txt";
    char plik3[] = "cos.txt";
    char plik4[] = "file_b_1";
    fi1 = fopen(plik1,"r");
    fi2 = fopen(plik3,"w");
    fi3 = fopen(plik4,"rb");
    fi4 = fopen("cos2.bin","wb");

    file_copy(fi1,fi2);
    file_copy(fi3,fi4);

    fclose(fi1);
    fclose(fi2);
    fclose(fi3);
    fclose(fi4);

    
    i = file_cmp(plik1,"tekst_2.txt");
    if(i==0)
        printf("Sa rowne\n");
    else printf("nie sa rowne\n");
    
    i = file_cmp(plik4,"file_b");
    if(i==0)
        printf("Sa rowne\n");
    else printf("nie sa rowne\n");
    
    return 0;
}