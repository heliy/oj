#include<cstdio>
#include<iostream>
#define N 8

using namespace std;

int cols[N];
int matrix[N][N];
int num;

void print(){
  int i, j;
  for(i = 0; i < N; i++){
    matrix[cols[i]][i] = 1;
  }
  printf("No. %d\n", ++num);
  for(i = 0; i < N; i++){
    printf("%d", matrix[i][0]);
    for(j = 1; j < N; j++){
      printf(" %d", matrix[i][j]);
    }
    printf("\n");
  }
  for(i = 0; i < N; i++){
    matrix[cols[i]][i] = 0;
  }
}

bool isok(int i, int j){
  int k;
  for(k = 0; k < i; k++){
    if(cols[k] == j || (i-k)== (j-cols[k]) || (k-i) == (j-cols[k])){
      return false;
    }
  }
  return true;
}

void isQueen(int i){
  if(i == N){
    print();
    return;
  }
  int j;
  for(j = 0; j < N; j++){
    if(isok(i, j)){
      cols[i++] = j;
      isQueen(i);
      i--;
    }
  }
}

int main(){
  int i, j, num;
  i = j = num = 0;
  for(i = 0; i < N; i++){
    cols[i] = 0;
    for(j = 0; j < N; j++){
      matrix[i][j] = 0;
    }
  }
  isQueen(0);
}
