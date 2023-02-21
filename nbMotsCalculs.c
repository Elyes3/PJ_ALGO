#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
int nbMotsDifferents(struct node* root)
{
    if (root == NULL)
        return 0;
    int cpt = 0;
        if (root-> val == '\0')
        {
            cpt = cpt + 1;
        }
       cpt = cpt + nbMotsDifferents(root->left);
       cpt = cpt +  nbMotsDifferents(root->right);
       return cpt;
}
int dicoNbMotsTotal(struct node* root)
{
    if ( root == NULL)
        return 0;
        int cpt = 0;
        cpt = cpt + root -> occ;
        cpt = cpt + dicoNbMotsTotal(root->left);
        cpt = cpt +  dicoNbMotsTotal(root->right);
       return cpt;
}