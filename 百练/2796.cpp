#include<stdio.h>

using namespace std;

int main(){
  int a, c, i, sum = 0;
  scanf("%d", &a);
  for(i = 0; i < 5; i++){
    scanf("%d", &c);
    if(c < a){
      sum += c;
    }
  }
  printf("%d\n", sum);
}
