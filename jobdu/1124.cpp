#include<stdio.h>

using namespace std;

/*  考虑范围不够  */
int root(int n){
  int r = 0;
  while(n > 0){
    r += n%10;
    n /= 10;
  }
  return r;
}

char array[100];

int main(){
  while(scanf("%s", array) != EOF){
    if(array[0] == '0'){
      break;
    }
    int i, n;
    for(n = 0, i = 0; array[i] != '\0'; i++){
      n += array[i] - '0';
    }
    while(n >= 10){
      n = root(n);
    }
    printf("%d\n", n);
  }
  return 0;
}
