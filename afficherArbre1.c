#include <stdio.h>
#include "headers.h"
#include <stdlib.h>
#include <string.h> 
#include <math.h>
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
