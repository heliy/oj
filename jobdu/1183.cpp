#include<stdio.h>

using namespace std;

int mamoru(int n){
  int p = n*n;
  if(n < 10){
    if(p%10 == n){
      return 1;
    }else{
      return 0;
    }
  }else{
    if(p%100 == n){
      return 1;
    }else{
      return 0;
    }    
  }
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(2 <= n && n < 100){
      if(mamoru(n)){
        printf("Yes!\n");
      }else{
        printf("No!\n");
      }
    }
  }
}
