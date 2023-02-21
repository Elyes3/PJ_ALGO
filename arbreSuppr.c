#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
void arbreSuppr(struct node * root){
    if (root != NULL)
        {
            arbreSuppr(root->left);
            arbreSuppr(root->right);
            free(root);
        }
}