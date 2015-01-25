#include<stdio.h>
#include<math.h>

int reverse(int a){
  int i, re = 0;
  for(i = 0; i < 4; i++){
    re += (a - (a/10)*10)*pow(10, 3-i);
    a /= 10;
  }
  return re;
}


int main(){
  int n;
  for(n = 1000; n*9 < 10000; n++){
    if(reverse(n*9) == n){
      printf("%d\n", n);
    }
  }
}
