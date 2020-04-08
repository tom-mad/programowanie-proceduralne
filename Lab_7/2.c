#include <stdio.h>
#include<string.h>
#define R 80
int main(int argc,char *argv[])	
{
	if(argc == 1)
	{
		printf("Brak Argumentu\n");
		return 0;	
	}
	int linie = 0,licznik = 0;
	char slowo[R];
	char *wsk;
	wsk = fgets(slowo, R,stdin);
	do
	{	
		if(strstr(slowo,argv[1]) != NULL)
		{	
			puts(slowo);
			linie ++;
			char *k= strstr(slowo,argv[1]);
			while(k!=NULL)
			{
				licznik++;
				k = strstr(k+1,argv[1]);
			}
		}
		wsk = fgets(slowo, R,stdin);
	}while (wsk != NULL);
	printf("\nIlość Lini=\t%d\nSuma wystąpień '%s' =\t%d\n",linie,argv[1],licznik);
	return 0;
}