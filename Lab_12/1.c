#include<stdio.h>
#include<stdlib.h>
struct Klient{
	char f_name[20],l_name[20],code[7];
	short age;
};
struct Klient * array_file(char * name,int *r){
	
	FILE * file = fopen(name,"r");
	if(file ==NULL)
		exit(-1);
	struct Klient * array = NULL;

	while(!feof(file)){
		
		array = realloc(array,(*r+1)*sizeof(struct Klient));
		fscanf(file,"%s%s%s%hd",array[*r].f_name,array[*r].l_name,array[*r].code,&array[*r].age);
		(*r)++;
	}
	
	fclose(file);
	return array;
}
int main(){
	int n = 0;
	struct Klient *array = array_file("spis.txt",&n);
	
	FILE *file = fopen("dane.dat","wb+");
	fwrite(array, sizeof(struct Klient) , n ,file);
	rewind(file);
	
	struct Klient help;
	puts("-----------------------\nOsoby pełnoletnie:");
	while(fread(&help, sizeof(struct Klient) , 1, file)) 
		if(help.age >=18)
			printf ("%s %s %s  %hd\n",  help.f_name, help.l_name,help.code,help.age); 
	fclose(file);
	free(array);
	return 0;
}