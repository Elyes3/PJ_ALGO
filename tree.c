#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
void main(){
char motPiocher[100];
struct node
{
struct node* right;
struct node* left;
char val;
int occ;
};
struct node* arbreConsVide(){
    return NULL; 
}
int arbreVide(struct node* root){
    if (root == NULL)
        return 1;
    return 0;
}
  struct node* creerNoeud(char value)
 {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> val = value;
    new_node -> occ = 0;
    new_node -> right = NULL;
    new_node -> left = NULL;
    return new_node;
 }
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
void arbreSuppr(struct node * root){
    if (root != NULL) 
        {
            arbreSuppr(root->left);
            arbreSuppr(root->right);
            free(root);
        }

}
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
int nombreAleatoire(int nombreMax) 
{ 
 return (rand() % nombreMax); 
}
void parcoursInfixe(struct node* root)
{   if (root!=NULL)
    {
    parcoursInfixe(root->left);
    printf("%c",root->val);
    parcoursInfixe(root->right);
    }
}
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
int nbMotsTotal(struct node* root)
{
    if ( root == NULL)
        return 0;
        int cpt = 0;
        cpt = cpt + root -> occ;
        cpt = cpt + nbMotsTotal(root->left);
        cpt = cpt +  nbMotsTotal(root->right);
       return cpt;
}
int piocherMot(char *motPioche) 
{ 
 FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
 int nombreMots = 0, numMotChoisi = 0, i = 0; 
 int caractereLu = 0; 
 dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
 // On vérifie si on a réussi à ouvrir le dictionnaire
 if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
 { 
 printf("\nImpossible de charger le dictionnaire de mots"); 
 return 0; // On retourne 0 pour indiquer que la fonction a échoué
 // À la lecture du return, la fonction s'arrête immédiatement.
 } 
 // On compte le nombre de mots dans le fichier (il suffit de compter les
 // entrées \n
 do
 { 
 caractereLu = fgetc(dico); 
 if (caractereLu == '\n') 
 nombreMots++; 
 } while(caractereLu != EOF); 
 numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
 // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon 
 rewind(dico); 
 while (numMotChoisi > 0) 
 { 
 caractereLu = fgetc(dico); 
if (caractereLu == '\n')
 numMotChoisi--; 
 } 
 /* Le curseur du fichier est positionné au bon endroit.
 On n'a plus qu'à faire un fgets qui lira la ligne */
 fgets(motPioche, 100, dico); 
 // On vire le \n à la fin

 motPioche[strlen(motPioche) - 1] = '\0'; 
 fclose(dico); 
 return 1; // Tout s'est bien passé, on retourne 1
}
int max(int a, int b) {
  return (a > b)? a : b;
}

int haut(struct node* node) {
  if (node == NULL)
    return 0;
  return 1 + max(haut(node->left), haut(node->right));
}
void graph_arbre(struct node *root){
    int h;
    int j=0;
    int c=0;
    int it=0;
    int dl=0;
    h=haut(root);
    int hauteur=h-1;
    h=h-1;
    struct node* ch;
    ch=creerNoeud('*');
  if(root == NULL) return;
printf(" %d \n", h);
  struct node *queue[1000];
  int front = 0;
  int rear = 0;

  queue[rear++] = root;

  while((front != rear)){
    struct node *temp = queue[front++];
    for(int k=1;k<=(pow(2,h-1));k++){
        printf("-");
    }
    if(temp->val!='\0'){
        printf("%c", temp->val);
    }
    else{
        printf("%c",'0');
    }
    for(int k=1;k<=(pow(2,h-1)+dl);k++){
        printf("-");
    }

    if (j==c){
    it++;
    c=c+pow(2,it);
    h--;
    printf("\n");
    }
    j++;
    if (j==(pow(2,hauteur)-1)){
        dl=1;
    }
    if (j<pow(2,hauteur)){
    if(temp->left != NULL)
      queue[rear++] = temp->left;
    else {
      queue[rear++] = ch;
    }
    if(temp->right != NULL)
      queue[rear++] = temp->right;
    else {
      queue[rear++] = ch;
    }
    }
  }
}


srand(time(NULL));
char buffer[100];
char ans;
struct node* root = NULL;
printf("\n");

for (int i = 0 ; i < 7 ; i++)
{
printf("\ndonner un mot :");
scanf("%s",buffer);
root = ajouterMot(buffer,root);
}
printf("le nombre de mots differents est : %d\n", nbMotsDifferents(root));
printf("le nombre de mots total est : %d\n",nbMotsTotal(root));
do{
printf("\nEntrez le mot dont vous souhaitez connaitre le nombre d'occurrences : ");
scanf("%s",buffer);
printf("Le nombre d'occurrences est %d\n",dicoNbOcc(buffer,root));
printf("Voulez-vous continuer ?\n");
getchar();
scanf("%c",&ans);
printf("ANS : %c",ans);
}
while(ans != 'n' );
}
