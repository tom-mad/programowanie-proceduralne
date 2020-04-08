#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char** podziel(char *strin, int *n);
void sort(char *lan[], int num);
char* sklej(char **A,int n);
int main(int argc,char *argv[])	
{
	if(argc == 1)
	{
		printf("Brak Argumentu\n");
		return 0;	
	}
	int r = 0;
	printf("------------------------------\nWczytany Łańcuch:\n");
	puts(argv[1]);
	printf("------------------------------\nPodzielony Łańcuch:\n");
	char **TAB = podziel(argv[1], &r);
	for(int k = 0;k<r;k++)
		puts(*(TAB+k));
	printf("------------------------------\nPosortowane Łańcuch:\n");
	sort(TAB, r);
	for(int k = 0;k<r;k++)
		puts(*(TAB+k));
	printf("------------------------------\nSklejone Łańcuchy\n");
	char *sklejone = sklej(TAB,r);
	puts(sklejone);
	free(sklejone);
	free(TAB);
	return 0;
}
char** podziel(char *strin, int *n)
{	
	char **tablan = NULL;
	int rows = 0, columns = 0;
	char separ[] = ")(,; .";
  	char* token;
  	token = strtok(strin,separ);
  	while (token != 0) 
  	{	
  		int k =0;
  		for(int i=0;i<rows;i++)
  		{
  			if(strcmp(*(tablan+i),token)==0)
  				k++;
  		}
  		if(k==0)
  		{
  			rows++;
  			if(columns<strlen(token))
  				columns = strlen(token)+1;
  			tablan = realloc(tablan,rows*sizeof(char*));
  			for(int i = 0;i<rows;i++)
				*(tablan + i) = realloc(*(tablan + i),columns*sizeof(char));
			strcpy(*(tablan+rows-1),token);
   		}
   		token = strtok(0,separ);
  	}
  	*n = rows;
	return tablan;
}
void sort(char *lan[], int num) 
{
	int i, j;
	char temp[100];
	for (i = 0 ; i < num-1;i++)
		for (j = i+1; j < num;j++ )
			if (strcmp(*(lan+i),*(lan+j)) > 0)
			{ 
				strcpy(temp,*(lan+i));
				strcpy(*(lan+i),*(lan+j));
				strcpy(*(lan+j),temp);
			}
	return;
}
char* sklej(char **A,int n)
{
char * tekst = NULL;
int r =0;
int k = 0;
for(int i = 0;i < n;i++)
{
k++;
r+=strlen(*(A+i));
tekst = realloc(tekst,r*sizeof(char)+k);
strcat(tekst,*(A+i));
strcat(tekst," ");
}
return tekst;
}
