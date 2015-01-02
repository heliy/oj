#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(n == 0){
      break;
    }
    int levels[101], i;
    for(i = 0; i < 101; i++){
      levels[i] = 0;
    }
    int mark;
    for(i = 0; i < n; i++){
      scanf("%d", &mark);
      levels[mark]++;
    }
    scanf("%d", &mark);
    printf("%d\n", levels[mark]);
  }
  return 0;
}
