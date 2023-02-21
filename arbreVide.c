#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
int arbreVide(struct node* root){
    if (root == NULL)
        return 1;
    return 0;
}
struct node* arbreConsVide(){
    return NULL;
}