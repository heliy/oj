#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
  int data;
  struct node * left;
  struct node * right;
};
typedef struct node * node_ptr;

node_ptr create(int d){
  node_ptr np = (node_ptr) malloc(sizeof(struct node));
  np->data = d;
  np->left = NULL;
  np->right = NULL;
  return np;
}

node_ptr insert(node_ptr tree, int d){
  if(tree == NULL){
    tree = create(d);
  }else{
    if(tree->data > d){
      tree->left = insert(tree->left, d);
    }
    if(tree->data < d){
      tree->right = insert(tree->right, d);
    }
  }
  return tree;
}

void preorder(node_ptr tree){
  if(tree != NULL){
    printf("%d ",tree->data);
    preorder(tree->left);
    preorder(tree->right);
  }
}

void inorder(node_ptr tree){
  if(tree != NULL){
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
  }
}

void postorder(node_ptr tree){
  if(tree != NULL){
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ",tree->data);
  }
}

void destory(node_ptr tree){
  if(tree!= NULL){
    destory(tree->left);
    destory(tree->right);
    free(tree);
  }
}

int main(){
  int n, i, x;
  while(scanf("%d", &n) != EOF){
    node_ptr t = NULL;
    for(i = 0; i < n; i++){
      scanf("%d", &x);
      t = insert(t, x);
    }
    preorder(t);
    printf("\n");
    inorder(t);
    printf("\n");
    postorder(t);
    printf("\n");
    destory(t);
  }
  return 0;
}
