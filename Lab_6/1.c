#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *concat(char **A,int n);
int main()	
{
	char *strings[ ] = {"The sun did not shine.","It was too wet to play."," So we sat in the house - ","All that cold, cold, wet day."};
	printf("------------------------------\nTablica Stringów:\n");
	int r = sizeof(strings)/sizeof(char*);
	for(int i=0; i<r;i++)
		printf("%s\n",*(strings+i));
	char * sklejona = concat(strings,r);
	printf("------------------------------\nTablica Sklejona:\n");
	printf("%s\n",sklejona);
	free(sklejona);
	return 0;
}
char *concat(char **A,int n)
{
	char * tekst =NULL;
	int r =0;
	for(int i = 0;i < n;i++)
	{
		r+=strlen(*(A+i));
		tekst = realloc(tekst,r*sizeof(char));
		strcat(tekst,*(A+i));
	}
	return tekst;
}

