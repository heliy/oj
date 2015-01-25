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

void destory(node_ptr tree){
  if(tree!= NULL){
    destory(tree->left);
    destory(tree->right);
    free(tree);
  }
}

int is_same(node_ptr np1, node_ptr np2){
  if(np1 == NULL && np2 == NULL){
    return 1;
  }else if(np1 == NULL || np2 == NULL){
    return 0;
  }else{
    if(np1->data == np2->data){
      return (is_same(np1->left, np2->left)*is_same(np1->right, np2->right));
    }else{
      return 0;
    }
  }
}

node_ptr line2np(char* line){
  int i;
  node_ptr np = NULL;
  for(i = 0; line[i] != '\0'; i++){
    np = insert(np, line[i] - '0');
  }
  return np;
}

int main(){
  int n, i;
  char line[11];
  while(scanf("%d", &n) != EOF && n != 0){
    fgets(line, 11, stdin);
    fgets(line, 11, stdin);
    node_ptr np = line2np(line);
    for(i = 0; i < n; i++){
      fgets(line, 11, stdin);
      node_ptr comnp = line2np(line);
      if(is_same(comnp, np)){
	puts("YES");
      }else{
	puts("NO");
      }
      destory(comnp);
    }
    destory(np);
  }
  return 0;
}
