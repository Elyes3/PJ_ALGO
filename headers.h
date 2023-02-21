struct node
{
struct node* right;
struct node* left;
char val;
int occ;
};
struct node* creerNoeud(char value);
int arbreVide(struct node* root);
struct node* arbreConsVide();
struct node* ajouterMot(char * str,struct node * root);
 char arbreRacineLettre(struct node* root);
 int arbreRacineNbOcc(struct node * root);
 struct node* arbreFilsGauche(struct node * root);
 struct node* arbreFilsDroit(struct node * root);
 void arbreSuppr(struct node * root);
 int dicoNbOcc(char mot[],struct node* root);
 int nbMotsDifferents(struct node* root);
 int dicoNbMotsTotal(struct node* root);
 int nombreAleatoire(int nombreMax);
 int piocherMot(char *motPioche,char * fileName);
 void print2DUtil(struct node* root, int space,char * str);
 void print2D(struct node* root);
 int max(int a, int b);
 int haut(struct node* node);
 void graph_arbre(struct node *root);
 