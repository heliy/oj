#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef struct node * node_ptr;

struct node{
  char letter;
  vector<node_ptr> nexts;
  boolean isWord;
};

node_ptr create(){
  node_ptr ptr = (node_ptr)malloc()
}


