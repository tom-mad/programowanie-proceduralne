#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int double_cmp(const void * a, const void * b){
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    	else return 0;
}
int cstring_cmp(const  void *a, const  void *b){ 
	return  strcmp(*(char**)a,*(char**)b);
}
int main(int argc,char *argv[])	{
	if(argc == 1){
		printf("Proszę uruchomić jeszccze raz z argumentami wywołania\n");
		return 0;	
	}
	int s;
	char *strings[] = { "Alex", "Bill","Bill","Celine", "Dexter", "Forest","Forest","Garcia","Garcia","Garcia", "Pedro","Zorro"};
	double numbers[] = {1.34, 1.34 , 4.34, 5.55, 5.67, 5.67, 5.67 ,7.76, 8.1, 8.1, 9.12, 11.23};
	for(int i = 1; i<argc;i++){
		double x = atof(argv[i]);
		s=0;
		if(x!=0){ 
			double * db = bsearch(&x,numbers,sizeof(numbers)/sizeof(double),sizeof(double),double_cmp);
			if(db!=NULL){
				for(int j =0;j<sizeof(numbers)/sizeof(double);j++){
					if(x==numbers[j]) s++;
				}
				printf("Liczba Rzeczywista:\t%.2f\tznajduje się w tablicy numbers i ilość ich wynosi %d\n",x,s);
			}
			else
				printf("Liczby Rzewistej:\t%.2f\tnie ma w tablicy numbers\n",x);
		}
		else{
			char ** strin = bsearch(&argv[i],strings,sizeof(strings)/sizeof(char*),sizeof(char*),cstring_cmp);
			if(strin!=NULL){
				for(int j =0;j<sizeof(strings)/sizeof(char*);j++){
					if(strcmp(argv[i],*(strings+j))==0) s++;
				}
				printf("Łańcuch:\t%s\tznajduje się w tablicy strings i ich suma wystąpień wynosi %d\n",argv[i],s);
			}
			else
				printf("Łańcuch:\t%s\tnie ma go w tablicy strings\n",argv[i]);
		}
		printf("----------------------------------------------------------\n");
	}
	return 0;
}