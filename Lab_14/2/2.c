#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tnode
{
    char word[20];
    int amount ;
    struct tnode * next;
} list;

void break_the_chain(list * head);
list * create_list(char * name);
void dodaj_rosnaco(list ** head, char * val);
void vision(list * view);

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("Proszę Podać nazwę pliku jako argument wywołania\n");
        return 0;
    }
    
    list *new = create_list(argv[1]);
    vision(new);
    FILE *out = fopen("plik_wyjsciowy.txt","w");
    if(!out)
        exit(-1);
    list *wsk = new;
    while(wsk){
        fprintf(out,"\t%s:%d\n",wsk->word,wsk->amount);
        wsk = wsk->next;
    }
    fclose(out);
    break_the_chain(new);

    return 0;
}
list * create_list(char * name)
{
    FILE * input_f = fopen( name, "r");
    if(input_f==NULL){
    puts("Nie istnieje taki plik lub brak dostępu do niego");
    exit(-1);
    }
    char h[20];
    list * head = NULL;
    list * wsk;
    while(fscanf (input_f,"%s", h)!=EOF)
    {
        wsk = head;
        while(wsk)
        {
            if(!strcmp(wsk->word,h)){
                ++(wsk->amount);
                break;
            }
            wsk = wsk->next;
        }
        if(!wsk)
            dodaj_rosnaco(&head,h);
    }
    
    fclose(input_f);
    return head;
}
void dodaj_rosnaco(list ** head, char * val)
{

	if(*head == NULL || (strcmp((*head)->word,val))>0){
        list * new_head = malloc(sizeof(list));
        new_head -> next = *head;
        strcpy(new_head->word,val);
        new_head->amount = 1;
        *head = new_head;
    }
	else{
		list *act = *head;
		while(act->next){
			if(strcmp(act->next->word,val)>0)
				break;
			act = act -> next;
		}
		list *new = malloc(sizeof(struct tnode));
		strcpy(new->word, val);
		new ->next = act->next;
		act->next =new;
        new->amount = 1;
	}
}
void break_the_chain(list * head)
{
  	list * chain = head;
  	while(chain){
    	head = chain->next;
    	free(chain);
    	chain = head; 
  	}
}
void vision(list * view){
  	if(!view){
		  printf("Lista Pusta\n");
		  return;
	}
  	while (view){
    	printf("%s:%d\n", view->word,view->amount);
    	view = view->next;
  	}
	return;
}