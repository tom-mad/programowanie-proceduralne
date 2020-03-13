#include <stdio.h>
#include<string.h>
#include <ctype.h>
void sw(char *p,int r);
void main()
{
	char tekst[] = "MAm Te soBie moC";
	int r=0;
	for(char *p=tekst;*p!='\0';p++)
		r++;
	printf("Tekst Przed Modyfikacją: %s \n",tekst);
	sw(tekst,r);
	printf("Tekst Po Modyfikacji: %s\n",tekst);
	return;
}
void sw(char *p,int r)
{
	for(char *a=p;a<p+r;a++)
		if(islower(*a))
		{
			for(char *b=p+r;b>a;b--)
			{
				r--;
				if(isupper(*b))
				{
					char z = *b;
					*b=*a;
					*a=z;				
					break;
				}
			}

		}
			
}