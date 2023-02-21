#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h>
struct node* creerNoeud(char value)
 {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> val = value;
    new_node -> occ = 0;
    new_node -> right = NULL;
    new_node -> left = NULL;
    return new_node;
 }