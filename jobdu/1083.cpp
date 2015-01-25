#include<stdio.h>

using namespace std;

int sum(long a){
  int s = 0;
  while(a > 0){
    s += a - (a/10)*10;
    a /= 10;
  }
  return s;
}

int main(){
  long a, b;
  while(scanf("%ld %ld", &a, &b) != EOF){
    printf("%d\n", sum(a) * sum(b));
  }
}
