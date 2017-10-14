#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

//prints the chars inside the list
void print_list(struct node *n){
    printf("printing llist \n");
    while(n){ //runs until node points to null
        printf("%c", n->c);
        n = n->next;
    }
    printf("\n");
}

//inserts newC at end of n
struct node * insert_front(struct node *n, char newC){
    //special case if n points to null (no llist yet)
    if(!n){
        n = (struct node *)malloc(sizeof(struct node));//allocates memory for a node * and assigns it to n
        n->next = 0; //points n to null
        n->c = newC;
        return n;
    }

    //otherwise...
    struct node *retCpy = n; //a copy of where n used to point to
    while(n->next){ n = n->next; } //runs up to last node in list
    n->next = (struct node *)malloc(sizeof(struct node)); //allocates memory for a node * and assigns it to next
    n->next->c =  newC;
    n->next->next = 0;
    return retCpy;
}

//takes a non null llist and frees its nodes returning pointer to first node
struct node * free_list(struct node *n){
    if(!n){return n;}//base case once n is null

    //recursive case
    free_list(n->next);//free the rest of the list
    free(n);//frees the original pointers after others have been freed
    n=0;
    return n;
}