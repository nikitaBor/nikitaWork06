#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main(){
    struct node *bill = 0;
    bill = insert_front(bill,'h');//creating first node of bill with character 'h'

    printf("testing print_list\n");
    print_list(bill);
    printf("adding 'i'\n");
    insert_front(bill, 'i');
    print_list(bill);
    printf("adding '!' and testing if insert_front returns correct pointer\n");
    print_list(insert_front(bill, '!'));
    printf("freeing bill and printing output of free_list\n");
    print_list(free_list(bill));
    return 0;
}