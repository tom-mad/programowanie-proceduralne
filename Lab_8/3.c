#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int double_cmp(const void * a, const void * b){
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    	else return 0;
}
int cstring_cmp(const  void *a, const  void *b){ 
	return  strcmp(*(char**)a,*(char**)b);
}
int tabchars_cmp(const  void *a, const  void *b){
	return  strcmp((char*)a,(char*)b);
}
void print_double_array(double * d_array,int n){
	for(int  i =0;i<n;i++){
		printf("%0.2f\t",*(d_array+i));
	}
	printf("\n");
	return;
}
void print_cstring_array(char **s_array, int n){
	for(size_t i =0;i<n;i++){
		printf("%s\n",*(s_array+i));
	}
	return;
} 
void print_tabchars_array(char (*ch_array)[10],int n){
	for(int i = 0; i < n;i++){
		printf("%s\n",*(ch_array+i));
	}
	return;
}
void sort_double_example() {
	double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
	size_t numbers_len = sizeof(numbers)/sizeof(double); 
	puts("*** Double sorting...");
	print_double_array(numbers,numbers_len); 
	qsort(numbers,numbers_len,sizeof(double), double_cmp);
	print_double_array(numbers,numbers_len); 
}
void sort_cstrings_example() {
	char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
	size_t strings_len = sizeof(strings)/sizeof(char*);
	puts("*** String sorting...");
	print_cstring_array(strings, strings_len); 
	qsort(strings,strings_len, sizeof(char*),cstring_cmp); 
	print_cstring_array(strings, strings_len); 
}
void sort_tabchars_example()   
{ 
	char tab_char[][10] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"}; 
  	size_t tab_char_N = sizeof(tab_char)/10;   
  	puts("*** table sorting..."); 
  	print_tabchars_array(tab_char, tab_char_N);
  	qsort(tab_char,tab_char_N,10 ,tabchars_cmp);  
  	print_tabchars_array(tab_char, tab_char_N);
 }
int main()
{
	sort_double_example();
	sort_cstrings_example();
	sort_tabchars_example();
	return 0;
}