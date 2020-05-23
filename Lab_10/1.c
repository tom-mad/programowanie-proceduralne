#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdarg.h> 
void va_cat(char **result,int num,...);
int main()  
{
  char **concat = calloc(1,sizeof(char*));;
  va_cat(concat,3,"If you never did You should.","These things are fun." ,"and Fun is good.");
  printf("------------------------------\nRezultat1:\n");
  printf("%s\n",*concat);
  free(concat);
  printf("------------------------------\n\n");
  concat = calloc(1,sizeof(char*));;
  va_cat(concat,4,"Sometimes ","you will never know ","the value of a moment " ,"until it becomes a memory.");
  printf("------------------------------\nRezultat2:\n");
  printf("%s\n",*concat);
  free(concat);

  return 0;
}
void va_cat(char **result,int num, ...){
  	int r = 1;
    char* str;
  
    va_list vl;

    puts("***Tablica Wejściowa:");
    va_start(vl,num);
    str = va_arg(vl , char*);
    for(int i = 0 ;i<num;i++){
    	puts(str);
      r+=strlen(str);
      *(result) = realloc(*(result),r*sizeof(char*));
      strcat(*(result),str);
      str = va_arg(vl , char*);
    } 

  va_end(vl);
  return;
}