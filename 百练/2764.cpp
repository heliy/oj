#include<stdio.h>

using namespace std;

char a[1001];
int root(int n){
  int s = 0;
  while(n > 0){
    s += n%10;
    n /= 10;
  }
  return s;
}

int main(){
  while(scanf("%s", a) != EOF){
    if(a[0] == '0'){
      break;
    }
    int s = 0, i;
    for(i = 0; a[i] != '\0'; i++){
      s += a[i] - '0';
    }
    while(s >= 10){
      s = root(s);
    }
    printf("%d\n", s);
  }
  return 0;
}
