#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
int dicoNbOcc(char mot[],struct node* root)
{
    int j = 0;
    struct  node* tmp = root;
    while (j<strlen(mot) && tmp != NULL)
    {
        if (mot[j] == tmp -> val)
        {
            j = j+1;
            if (j != strlen(mot))
                tmp = tmp -> left;
        }
        else
        {
            tmp = tmp -> right;
        }

    }
        if (tmp == NULL)
        {

            return 0;
        }
        else
        {
            if (tmp->left !=NULL)
            {
            if (tmp -> left -> val == '\0')
            {
                tmp = tmp -> left;
                return tmp -> occ;
            }
            else if ( tmp -> left -> val != '\0' && tmp -> left -> right !=NULL)
            {
                tmp = tmp -> left;
                while (tmp != NULL)
                {
                    tmp = tmp -> right;
                    if (tmp -> val == '\0')
                        return tmp -> occ;
                }
                return 0;
            }
            else
                return 0;
            }

        }
}