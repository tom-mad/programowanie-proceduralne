#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Klient{
	char l_name [20],f_name[20], code[7];
	int age;
};
int compare_st(const void *a, const void *b){
  	struct Klient A = *(struct Klient *)a;
  	struct Klient B = *(struct Klient *)b;
	int cmp = strcmp(A.f_name, B.f_name);
	if (cmp == 0){
    	return strcmp(A.l_name, B.l_name);
  	}
  	return cmp;
}
	int main(){
  	struct Klient klie[6];

  	for (int i = 0;i < 6;i++){
    	scanf("%s", klie[i].l_name);
    	scanf("%s", klie[i].f_name);
    	scanf("%s", klie[i].code);
    	scanf("%d", &klie[i].age);
  }

  	qsort(klie, 6, sizeof(klie[0]), compare_st);
  	puts("***Wynik:");
  	for (int i = 0; i < 6; i++){
  	   	printf(" %s   %s  kod: %s  wiek: %d\n", klie[i].l_name, klie[i].f_name, klie[i].code, klie[i].age);
  	}

  return 0;
}

