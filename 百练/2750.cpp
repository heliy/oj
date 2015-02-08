#include<stdio.h>

using namespace std;

int min(int a){
  if(a%4 == 0){
    return a/4;
  }else{
    return a/4+1;
  }
}

int main(){
  int n, a, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a);
    if(a%2 == 0){
      printf("%d %d\n", min(a), a/2);
    }else{
      printf("0 0\n");
    }
  }
  return 1;
}
