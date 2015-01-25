#include<stdio.h>

using namespace std;

int same(int A, int B, int K){
  while(K > 0){
    if((A-(A/10)*10) != (B-(B/10)*10)){
      return 0;
    }
    A = A/10;
    B = B/10;
    K--;
  }
  return 1;
}


int main(){
  int A, B, K;
  while(scanf("%d %d %d", &A, &B, &K) != EOF){
    if(A == 0 && B == 0){
      break;
    }
    if(same(A, B, K)){
      printf("-1\n");
    }else{
      printf("%d\n", A+B);
    }
  }
  return 0;
}
