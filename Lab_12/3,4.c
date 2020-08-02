#include <stdio.h>
#include <stdlib.h>

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
  	
  	while (view){
    	printf("%c\n", view->value);
    	view = view->next;
  	}
}

void break_the_chain(struct tnode** head)
{
  	
  	struct tnode* chain = *head;
  	while(chain)
    {
    	*head = chain->next;
    	free(chain);
    	chain = *head; 
  	}
    *head = NULL;
}


int main(){
  	
  	struct tnode *head = NULL;
  
  	dodaj_na_koniec(&head,'u');
  	dodaj_na_poczatek(&head,'a');
  	dodaj_na_poczatek(&head,'c');
  	dodaj_na_poczatek(&head,'v');
 	  dodaj_na_poczatek(&head,'f');
  	dodaj_na_poczatek(&head,'t');
  	dodaj_na_koniec(&head,'i');
  
  	vision(head);

  	break_the_chain(&head);

	return 0;
}