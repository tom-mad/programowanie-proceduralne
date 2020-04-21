#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
char pi_form[7] = "";
int i;
for (i=0; i<7; i+=2){
	sprintf(pi_form, "%%.%dlf",i);
	printf("FORMAT %s ->",pi_form); 
	strcat(pi_form,"\n");                  
	printf(pi_form,M_PI);
}
return 0; 
}