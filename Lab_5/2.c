#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_string_array(char ** wsk,size_t n);
char * min_string (char ** wsk,size_t n);
int main()
{
	char * strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
	char * wsk_string;
	size_t strings_len = sizeof(strings)/sizeof(char*);
	printf("Wypisanie Stringów:\n");
	print_string_array(strings, strings_len);
	wsk_string = min_string(strings,strings_len);
	printf("\nNajmniejszy String:\n%s\n", wsk_string);
	free(wsk_string);
	return 0;
}
void print_string_array(char ** wsk,size_t n)
{
	for(size_t i =0;i<n;i++)
	{
		printf("%s\n",*(wsk+i));
	}
	return;
}
char * min_string (char ** wsk,size_t n)
{
	char * min;
	min = malloc(sizeof(*wsk)*sizeof(char));
	strcpy (min , *wsk);
	for(size_t i = 1;i < n;i++)
	{
		if(strcmp(*(wsk+i),min) < 0)
		{
			min = NULL;
			min = realloc(min,sizeof(*(wsk+i))*sizeof(char));
			strcpy (min , *(wsk+i)) ;
		}	
	}
	return min;
}


