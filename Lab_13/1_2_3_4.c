#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

struct tnode{
  char value;
  struct tnode * next;
};

void dodaj_na_poczatek(struct tnode ** head, char val){
  
  struct tnode * inception = malloc(sizeof(struct tnode*));
  inception->value = val;
  inception->next = *head;
  *head = inception;

}
void dodaj_na_koniec(struct tnode ** head, char val){
	
	if(*head == NULL)
		dodaj_na_poczatek(head,val);
	else{
		struct tnode *extremity = *head;
		while(extremity->next)
			extremity = extremity->next;
		extremity->next = malloc(sizeof(struct tnode*));
		extremity->next->next = NULL;
		extremity->next->value = val;
	}
}
void vision(struct tnode* view){
  	if(!view){
		  puts("NULL");
		  return;
	}
  	while (view){
    	printf("'%c'\t", view->value);
    	view = view->next;
  	}
	puts("\n");
	return;
}
void break_the_chain(struct tnode* head){
  	
  	struct tnode* chain = head;
  	while(chain){
    	head = chain->next;
    	free(chain);
    	chain = head; 
  	}
}
void transposition(struct tnode ** head){ // 
	struct tnode *p,*pc;
	if( head ){
		pc = *head;
    	while( pc->next ){
      		p = pc->next;
      		pc->next = p->next;
      		p->next = *head;
      		*head = p;
    	}
  	}
  return;
} //I zadanie
void dodaj_rosnaco(struct tnode ** head, char val){      
	
	if(*head == NULL || (*head)->value>val)
		dodaj_na_poczatek(head,val);
	else{
		struct tnode *act = *head;
		while(act->next){
			if(act->next->value > val)
				break;
			act = act -> next;
		}
		struct tnode *new = malloc(sizeof(struct tnode));
		new->value = val;
		new ->next = act->next;
		act->next =new;
	}
} // II zadania
struct tnode * delete(struct tnode ** head,char val){
	
	struct tnode * new_head = NULL;
	struct tnode * wsk = *head;
	struct tnode * previous = NULL;
	struct tnode * next = wsk -> next;
	struct tnode *one;
	while( wsk ){
		
		if(tolower(wsk->value) == tolower(val)){
            if(new_head){
                one = new_head;
                while(one->next)
                    one = one->next;
                one->next = wsk;
                wsk->next= NULL;
            }
            else{
                new_head = wsk;
                *head = wsk->next;
                wsk->next = NULL;
            }
            if(previous){
                previous -> next = next; 
                wsk = next;
                if(wsk) 
				    next = wsk->next;
			}
			else{
				*head = next;
				wsk = *head;
                if(wsk) 
				    next = wsk ->next;
			}
		}
		else{
			previous = wsk; 
			wsk = next;
			if(wsk) 
				next = wsk ->next;
		}
		
	}
	
	return new_head;
}//III zadanie
struct tnode * connect(struct tnode **list_1,struct tnode **list_2){
    struct tnode *con = NULL;
    struct tnode *help = NULL;
    struct tnode * wsk=NULL;
    int x;
    while(*list_1||*list_2)
    {
        if(*list_1 && *list_2)
        {
            if((*list_1)->value >(*list_2)->value)x=1;
            else x =0;
        }
        else
        {
            if(*list_1) x = 0;
            else x = 1;
        }
        if(x)
            help = delete(list_2,(*list_2)->value);
        else
            help = delete(list_1,(*list_1)->value);  
        if(con)
        {
            wsk = con;
            while(wsk->next)
                wsk = wsk->next;
            wsk->next = help;
        }
        else
            con = help;
        
    }
    return con;
}//IV zadanie
int main(void)
{
    puts("------------------------------\nI zadanie");
    struct tnode *head = NULL;
    dodaj_na_koniec(&head,'f');
    dodaj_na_koniec(&head,'d');
    dodaj_na_koniec(&head,'u');
    dodaj_na_koniec(&head,'i');
    puts("Przed:");
    vision(head);
    transposition(&head);
    puts("Po:");
    vision(head);
    break_the_chain(head);

    puts("------------------------------\nII zadanie");
    head = NULL;
    dodaj_na_koniec(&head,'a');
    dodaj_na_koniec(&head,'j');
    dodaj_na_koniec(&head,'k');
    dodaj_na_koniec(&head,'z');
    puts("Przed:");
    vision(head);
    dodaj_rosnaco(&head,'w');
    puts("Po:");
    vision(head);
    break_the_chain(head);
    head = NULL;

    puts("------------------------------\nIII zadanie");
    struct tnode component[] = {{'a',component+1},{'t',component+2},{'o',component+3},{'k',component+4},{' ',component+5},
    {'a',component+6},{'m',component+7},{' ',component+8},{'a',component+9},{'l',component+10},{'A',NULL}};
    head = component;
    puts("Przed:");
    vision(head);
    struct tnode *left = delete(&head,'a');
    puts("Po:");
    puts("HEAD:");
    vision(head);
    puts("LEFT:");
    vision(left);
    head = NULL;
    puts("------------------------------\nIV zadanie");
    struct tnode * lista_1 = NULL;
    struct tnode * lista_2 = NULL;
    dodaj_na_koniec(&lista_1,'a');
    dodaj_na_koniec(&lista_1,'k');
    dodaj_na_koniec(&lista_1,'l');
    dodaj_na_koniec(&lista_1,'z');
    
    dodaj_na_koniec(&lista_2,'a');
    dodaj_na_koniec(&lista_2,'b');
    dodaj_na_koniec(&lista_2,'l');
    dodaj_na_koniec(&lista_2,'n');
    dodaj_na_koniec(&lista_2,'w');
    
    puts("Przed:");
    puts("lista_1:");
    vision(lista_1);
    puts("lista_2:");
    vision(lista_2);

    head = connect(&lista_1,&lista_2);
    
    puts("Po:");
    
    puts("lista:");
    vision(head);
    puts("lista_1:");
    vision(lista_1);
    puts("lista_2:");
    vision(lista_2);
    
    break_the_chain(head);
    
    return 0;
}