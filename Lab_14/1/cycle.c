#include"cycle.h"

void print_list(struct tnode* head)
{
    if(head == NULL){
        printf("Nie istnieje lista\n");
        return;
    }
    struct tnode *wsk = head;
    do{
        printf("[%d]  ",wsk->value);
        wsk = wsk -> next;
    }while(head != wsk);
    printf("\n");
    return;
}

struct tnode* add_el(struct tnode * head, struct tnode* el)
{
    if(!head)
    {
        if(!el)
            return NULL;
        el->next = el;
        return el;
    }
    struct tnode *wsk = head;
    while(wsk->next != head)
        wsk = wsk->next;
    wsk->next = el;
    el ->next = head;
    return head;
}

void del_el(struct tnode** head, int var)
{
    if(!*head)
    {
        printf("Lista pusta");
        return;
    }
    int r = 0;
    int l = 0;
    struct tnode *act =*head;
    while(act->next!=*head){
        act = act ->next;
        r++;
    }
    struct tnode *previous = act;
    act = *head;
    struct tnode *next = act->next;
    
    for(int i = 0 ; i <= r;i++)
    {
        if(act->value==var)
        {
            if(i==l){
                *head = next;
                l++;
            }
            previous->next = next;
            act = next;
            next = act->next;
        }
        else{
            previous = act;
            act = next;
            next = next->next;
        }
    }
    if(l==r)
        *head = NULL;
}

struct tnode* add_list(struct tnode* head1, struct tnode* head2)
{
    if(!head1 || !head2)
    {
        if(!head1)
            return head2;
        return head1;
    }
    struct tnode *wsk_1 = head1;
    struct tnode *wsk_2 = head2;
    while(wsk_1->next != head1)
        wsk_1 = wsk_1->next;
    while(wsk_2->next != head2)
        wsk_2 = wsk_2->next;
    wsk_1 -> next = head2;
    wsk_2 -> next = head1;
    return head1;
}

struct tnode* div_list(struct tnode** head)
{
    if(!*head)
        return NULL;
    int r = 0;
    int l =0;
    struct tnode *list = NULL;
    struct tnode *act =*head;
    while(act->next!=*head){
        act = act ->next;
        r++;
    }
    struct tnode *previous = act;
    act = *head;
    struct tnode *next = act->next;
    for(int i = 0 ; i <= r;i++)
    {
        if(act->value % 2)
        {
            if(i==l){
                *head = next;
                l++;
            }

            previous -> next = next;
            list = add_el(list,act);
            act = next;
            next = next ->next;
        }
        else{
            previous = act;
            act = next;
            next = next ->next;
        }
    }
    if(l==r+1)
        *head = NULL;
    return list;
}
void rev_list(struct tnode *head)
{
    if(!head)
    {
        printf("Lista pusta");
        return;
    }
    struct tnode *act = head;
    while(act->next != head){
        act = act ->next;
    }
    struct tnode *previous = act;
    act = head;
    struct tnode *next = act->next;

    while(1)
    {
        act->next = previous;
        previous = act;
        act = next;
        next = act ->next;
        if(act ==head)
            break;
    } 
}

void free_list(struct tnode **head)
{
    struct tnode * help = (*head)->next;
    struct tnode * h ;
    while(help!=*head)
    {
        h=help->next;
        help = h;
    }
    *head = NULL;
    return;    
}