#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  char c;
  struct node * left;
  struct node * right;
};
typedef struct node *  node_ptr;

char pre[30];
char in[30];


node_ptr create(char c){
  node_ptr np = (node_ptr) malloc(sizeof(struct node));
  np->c = c;
  np->left = NULL;
  np->right = NULL;
  return np;
}

int find(char c){
  int i = 0;
  while(in[i] != '\0'){
    if(in[i] == c){
      return i;
    }
    i++;
  }
  return -1;
}

node_ptr insert(node_ptr np, int insert_in){
  if(np == NULL){
    np = create(in[insert_in]);
  }else{
    int root_in = find(np->c);
    if(root_in < insert_in){
      np->right = insert(np->right, insert_in);
    }else{
      np->left = insert(np->left, insert_in);
    }
  }
  return np;
}

void post(node_ptr np){
  if(np == NULL){
    return;
  }
  post(np->left);
  post(np->right);
  printf("%c", np->c);
}

void destory(node_ptr np){
  if(np != NULL){
    destory(np->left);
    destory(np->right);
    free(np);
  }
}

int main(){
  while(scanf("%s", pre) != EOF){
    scanf("%s", in);
    int i, j, len = strlen(pre);
    in[len] = '\0';
    pre[len] = '\0';
    node_ptr np = NULL;
    for(i = 0; i < len; i++){
      j = find(pre[i]);
      np = insert(np, j);
    }
    post(np);
    printf("\n");
    destory(np);
  }
  return 0;
}
