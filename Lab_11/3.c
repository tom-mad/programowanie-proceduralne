#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct xyz{
    char car;
    struct xyz *st;
};




struct xyz * func(FILE * fbi,int * n){
    
    fseek(fbi, 0, SEEK_END);
    long size = ftell(fbi);
    rewind (fbi);
    struct xyz *TAB = malloc(size);
    long a = sizeof(struct xyz);
    *n = size/a;
    fread(TAB,sizeof(struct xyz),size/a,fbi);
    return TAB;

}

int main(void)
{
    struct xyz a,b,c;
    
    a.st = &b;
    b.st = &c;
    c.st = &a;

    a.car = 'a';
    a.st->car = 'b';
    a.st->st->car = 'c';

    printf("a.car:\t%c\nb.car:\t%c\nc.car:\t%c\n", b.st->st->car, b.car, b.st->car);
 
    c.st->car = toupper(c.st->car);
    c.st->st->car = toupper(c.st->st->car);
    c.car = toupper(c.car);

    FILE *f1 = fopen("dane.txt", "w");
    FILE *f2 = fopen("dane.dat", "wb");
	
    if(f1 == NULL || f2 == NULL)
    {
        printf("Blad");
        exit(EXIT_FAILURE);
    }
	
	fprintf(f1,"%c\t%p\n", a.car, a.st);
	fprintf(f1,"%c\t%p\n", b.car, b.st);
	fprintf(f1,"%c\t%p\n", c.car, c.st);
	
	fwrite(&a, sizeof(struct xyz), 1, f2);
	fwrite(&b, sizeof(struct xyz), 1, f2);
	fwrite(&c, sizeof(struct xyz), 1, f2);
	
	fclose(f1);
	fclose(f2);
    int r;
    f2 = fopen("dane.dat","r");
    struct xyz *TAB = func(f2,&r);
    fclose(f2);
    for(int i = 0; i<r;i++){
        printf("TAB[%d].car='%c'\tTAB[%d].st=%p\n",i,TAB[i].car,i,TAB[i].st);
    }
    free(TAB);
    return 0;
}






