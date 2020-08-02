#include"cycle.h"
int main(void)
{
    struct tnode component[]= {{1,NULL},{3,NULL},{5,NULL},{3,NULL},{13,NULL},{27,NULL}};
    struct tnode *head = NULL;
    for(int i = 0;i<sizeof(component)/sizeof(struct tnode);i++)
        head = add_el(head,&component[i]);
    puts("\n-----------------------------------\nLista1");
    print_list(head);
    
    puts("\n-----------------------------------\nUsuniecie liczby 3 z Lista1");
    del_el(&head,3);
    print_list(head);

    struct tnode component1[]= {{7,NULL},{63,NULL},{45,NULL},{70,NULL},{3,NULL},{57,NULL}};
    struct tnode *head1 = NULL;
    for(int i = 0;i<sizeof(component1)/sizeof(struct tnode);i++)
        head1 = add_el(head1,&component1[i]);
    puts("\n-----------------------------------\nLista2");
    print_list(head1);
    
    puts("\n-----------------------------------\nPolaczona Lista1 i Lista2");
    head = add_list(head, head1);
    print_list(head);

    puts("\n-----------------------------------\nPolaczona Lista1 i Lista2 podzielona na parzyste i nieparzyste\nParzyste:");
    head1 = div_list(&head);
    print_list(head);
    puts("\nNieparzyste:");
    print_list(head1);

    puts("\n-----------------------------------\nLista liczb nie parzystych odwrocona");
    rev_list(head1);
    print_list(head1);
    
    
    free_list(&head);
    free_list(&head1);
    return 0;
}
