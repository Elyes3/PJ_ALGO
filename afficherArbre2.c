#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
#define COUNT 10
void print2DUtil(struct node* root, int space,char * str)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space,"(R)");
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    if(root->val!='\0'){
        printf("%c%s", root->val,str);
    }
    else{
        printf("\\o%s occ: %d",str, root->occ);
    }

    print2DUtil(root->left, space,"(L)");
}

void print2D(struct node* root)
{
    print2DUtil(root, 0,"");
}
