#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
 char arbreRacineLettre(struct node* root){
    if (arbreVide(root) == 1)
        return '\0' ;
    return root -> val;
}
int arbreRacineNbOcc(struct node * root){
    if (arbreVide(root) == 1)
        return 0;
    return  root -> occ;
}
struct node* arbreFilsGauche(struct node * root){
    if (arbreVide(root) == 1)
        return NULL;
    else if (arbreVide(root->left) == 1 )
        return NULL;
    return root->left;
}
struct node* arbreFilsDroit(struct node * root){
    if (arbreVide(root) == 1)
        return NULL;
    else if (arbreVide(root->right) == 1 )
        return NULL;
    return root->right;
}