#include <stdio.h>
#include <stdlib.h>

struct tnode{
  int value;
  struct tnode * next;
};
void dodaj_na_poczatek(struct tnode ** head, int val){
  
  struct tnode * inception = malloc(sizeof(struct tnode*));
  inception->value = val;
  inception->next = *head;
  *head = inception;

}
void dodaj_na_koniec(struct tnode ** head, int val){
	
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
void vision(struct tnode* head){
    struct tnode* wsk = head;
    while (wsk)
    {
        printf("%d\t", wsk->value);
        wsk = wsk->next;
    }
    puts("\n");
}
void break_list(struct tnode* f,struct tnode* d,struct tnode* t){
    struct tnode* wsk = f;
    while(wsk&&t!=wsk){
    	f = wsk->next;
    	free(wsk);
    	wsk = f; 
  	}
    wsk = d;
    while(wsk&&t!=wsk){
    	d = wsk->next;
    	free(wsk);
    	wsk = d; 
  	}
    wsk = t;
  	while(wsk){
    	t = wsk->next;
    	free(wsk);
    	wsk = t; 
  	}
}

void cat(struct tnode ** head1,struct tnode ** head2,struct tnode *help){
    struct tnode * wsk;
    if(*head1)
    {
        wsk = *head1;
        while(wsk ->next)
            wsk = wsk->next;
        wsk -> next = help;
    }
    else
        *head1 = help;
    if(*head2)
    {
        wsk = *head2;
        while(wsk ->next)
            wsk = wsk->next;
        wsk -> next = help;
    }
    else
        *head2 = help;      
}
int main(void)
{
    struct tnode * L_1 = NULL;
    struct tnode * L_2 = NULL;
    struct tnode * h = NULL;
    int help;
    int r=0;
    while(1)
    {
        scanf("%d",&help);
        if(!(help>=0&&help<20))
            break;
        if(!help)
            r=10;
        switch (help%2+r)
        {
            case 0:
                dodaj_na_koniec(&L_1,help);
                break;
            case 1:
                dodaj_na_koniec(&L_2,help);
                break;
            default:
                dodaj_na_koniec(&h,help);
                break;
        }
    }
    cat(&L_1,&L_2,h);
    puts("L_1:");
    vision(L_1);
    
    puts("L_2:");
    vision(L_2);
    
    break_list(L_1,L_2,h);
    return 0;
}