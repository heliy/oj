#include<iostream>
#define N 10010

using namespace std;

int edges[N][N];
int wayto[N][N];

void clear(){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      edges[i][j] = 0;
      wayto[i][j] = 0;
    }
  }
  n = 0;
}
int n;

int main(){
  int i, j, n;
  clear();
  while(cin >> i >> j){
    if(j == 0 && i == 0){
      clear();
    }

  }
}
