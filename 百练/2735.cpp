#include<stdio.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int x = 0, p = 1;
  while(n > 0){
    x += (n%10) * p;
    p *= 8;
    n /= 10;
  }
  printf("%d\n", x);
  return 0;
}
