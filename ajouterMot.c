#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h>
 struct node* ajouterMot(char * str,struct node * root){
        struct node* tmp;
        if (arbreVide(root) == 1 )
        {
            for(int i = 0 ; i < strlen(str) ; i++)
            {
                if (i == 0)
                {
                    printf("LEFT");
                    root = creerNoeud(str[i]);
                    tmp = root;
                }
                else
                {   printf("LEFT");
                    tmp -> left = creerNoeud(str[i]);
                    tmp = tmp -> left;
                }
            }
            struct node* finalElmnt = creerNoeud('\0');
            finalElmnt -> occ = 1;
            tmp -> left  = finalElmnt;
            return root;
        }
        else
        {
            struct node* tmp = root;
            int j = 0 ;
            while(j<strlen(str))
            {
                if (str[j] == tmp -> val )
                {
                if (tmp -> left != NULL)
                {


                    j = j + 1;
                    if (j!=strlen(str))
                    {   printf("LEFT NO CREA ");
                        tmp = tmp -> left;
                    }
                }
                else
                {   printf("LEFT CREA ");
                    j = j + 1;
                    tmp -> left = creerNoeud(str[j]);
                    tmp = tmp -> left;
                    if (j == strlen(str) -1)
                        j++;
                }
                }
                else
                {
                    if (tmp -> right != NULL)
                    {
                        printf("RIGHT NO CREA ");
                        tmp = tmp -> right;
                    }
                    else
                    {   printf("RIGHT CREA ");
                        tmp -> right = creerNoeud(str[j]);
                        tmp = tmp -> right;
                        if (j == strlen(str) -1)
                            j++;
                    }
                }


            }
            if (tmp -> left != NULL)
            {
                if (tmp -> left -> val == '\0')
                {
                tmp -> left -> occ = tmp -> left -> occ + 1;
                }
                else
                {
                tmp = tmp -> left;
                if (tmp -> right != NULL){
                while (tmp -> right != NULL)
                {
                    if (tmp -> val == '\0')
                        break;
                    else
                        tmp = tmp -> right;
                }
                if (tmp != NULL && tmp -> val == '\0'){
                    tmp -> occ = tmp -> occ +1;
                }
                }
                else
                {
                    tmp-> right = creerNoeud('\0');
                    tmp = tmp -> right;
                    tmp-> occ = 1;
                }
                }
            }
            else
            {
                tmp -> left = creerNoeud('\0');
                tmp = tmp -> left;
                tmp -> occ = 1;
            }
            return root;
        }

 }