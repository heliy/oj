#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int per[7];
char line[7];

void print(int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%c", line[per[i]]);
  }
  printf("\n");
}

bool isok(int i, int j){
  int k;
  for(k = 0; k < i; k++){
    if(j == per[k]){
      return false;
    }
  }
  return true;
}

void muta(int n, int i){
  if(i == n){
    print(n);
    return;
  }
  int j;
  for(j = 0; j < n; j++){
    if(isok(i, j)){
      per[i] = j;
      muta(n, i+1);
    }
  }
}

int main(){
  cin >> line;
  int n = strlen(line);
  sort(line, line+n);
  muta(n, 0);
}
