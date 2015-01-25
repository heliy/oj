#include<stdio.h>
#include<math.h>

using namespace std;

int reverse(int n){
  int i, re = 0;
  int p = log(n)/log(10);
  for(i = 0; i <= p; i++){
    re += (n-(n/10)*10) * pow(10, p - i);
    n /= 10;
  }
  return re;
}

int main(){
  int n;
  for(n = 0; n < 256; n++){
    if(reverse(n*n) == n*n){
      printf("%d\n", n);
    }
  }
  return 0;
}
