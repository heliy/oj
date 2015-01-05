#include<stdio.h>
#include<stdlib.h>

using namespace std;

int array[201];

int find(int n, int f){
  int i;
  for(i = 0; i < n; i++){
    if(f == array[i]){
      return i;
    }
  }
  return -1;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int i,f;
    for(i = 0; i < n; i++){
      scanf("%d",array+i);
    }
    scanf("%d", &f);
    printf("%d\n", find(n, f));
  }
}
