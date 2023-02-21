#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "headers.h"

#define BADKEY -1

void main(){
typedef struct { char *key; int val; } t_symstruct;

static t_symstruct lookuptable[] = {
    { "help", 0 }, { "ajouter", 1 }, { "clear", 2 }, { "suppr", 3 }, { "nbTotal", 4 }, { "nbDiff", 5 }, { "arbre1", 6 }, { "arbre2", 7 }, { "exit", 8 },{"randomize",9},{"nbOcc",10}
};
#define NKEYS (sizeof(lookuptable)/sizeof(t_symstruct))
int keyfromstring(char *key)
{
    int i;
    for (i=0; i < NKEYS; i++) {
        t_symstruct *sym = &lookuptable[i];
        if (strcmp(sym->key, key) == 0)
            return sym->val;
    }
    return BADKEY;
}
char motPiocher[100];


srand(time(NULL));
char buffer[100];
char ans[25];
char conf;
struct node* root = NULL;
printf("\n");
printf("Bonjour ! Voici les operations possible du programme :\n\nhelp : l'affichage du liste d'operations.\najouter : l'ajout d'un mot au dictionnaire.\nclear : efface l'ecran de l'affichage\nsuppr : suppression du dictionnaire.\nnbTotal : l'affichage du nombre total des mots du dictionnaire.\nnbDiff : l'affichage du nombre des mots differents.\narbre1 : l'affichage du l'arbre (version 1).\narbre2 : l'affichage du l'arbre (version 2).\nnbOcc : Connaitre le nombre d'occurences d'un mot.\nrandomize : Generer l'arbre a partir d'un fichier dictionnaire aleatoirement \nexit : quitter le programme.\n");

do{
   printf("\n>");
   scanf("%s",ans);
   switch (keyfromstring(ans)){
       case -1 :
            printf("Operation invalide ! Voici les options possible : \n");
       case 0 :
            printf("\najouter : l'ajout d'un mot au dictionnaire.\nclear : efface l'ecran de l'affichage\nsuppr : suppression du dictionnaire.\nnbTotal : l'affichage du nombre total des mots du dictionnaire.\nnbDiff : l'affichage du nombre des mots differents.\narbre1 : l'affichage du l'arbre (version 1).\narbre2 : l'affichage du l'arbre (version 2).\nnbOcc : Connaitre le nombre d'occurences d'un mot.\nrandomize : Generer l'arbre a partir d'un fichier dictionnaire aleatoirement \nexit : quitter le programme.\n");
            break;
       case 1 :
            printf("\nDonner un mot : ");
            scanf("%s",buffer);
            root = ajouterMot(buffer,root);
            break;
       case 2 :
            system("cls");
            break;
       case 3 :
            if(arbreVide(root))
                    printf("\nLe dictionnaire est deja vide !");
                else{
                    arbreSuppr(root);
                    root = creerNoeud('\0');
                    struct node* tmp = root;
                    root = NULL;
                    free(tmp);
                    printf("\nLe dictionnaire est maintenant vide !");
                }
            break;
       case 4 :
            printf("\nLe nombre de mots total est : %d\n",dicoNbMotsTotal(root));
            break;
       case 5 :
            printf("\nLe nombre de mots differents est : %d\n", nbMotsDifferents(root));
            break;
       case 6 :
            if(arbreVide(root))
                    printf("\nLe dictionnaire est vide !");
                else{
                    graph_arbre(root);
                }
            break;
       case 7 :
            if(arbreVide(root))
                    printf("\nLe dictionnaire est vide !");
                else{
                    print2D(root);
                }
            break;
       case 8 :
            break;
       case 9 :

            printf("Combien de mots voulez-vous piocher\n");
            int nbW;
            char fileName[50];
            char word[100];
            scanf("%d",&nbW);
            srand(time(NULL));
            printf("Donner le nom du fichier\n");
            scanf("%s",fileName);
            for (int i = 0 ; i<nbW ; i++)
            {
                int c = piocherMot(word,fileName);
                if (c != 0)
                    root = ajouterMot(word,root);
                else break;
            }
            break;
        case 10 : 
            
            printf("Saisir un mot dont vous souhaitez connaitre le nombre d'occurences\n");
            char occWord[100];
            scanf("%s",occWord);
            int c = dicoNbOcc(occWord,root);
            printf("Le nombre d'occurrences du mot %s est %d\n", occWord,c);
            break;

   }


}while(strcmp(ans, "exit"));
arbreSuppr(root);
}
