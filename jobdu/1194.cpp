#include<stdio.h>

using namespace std;

int hachi[50];

int main(){
  int N;
  while(scanf("%d", &N) != EOF){
    int i = 0;
    do{
      hachi[i] = N%8;
      N /= 8;
      i++;
    }while(N > 0);
    for(i--; i >= 0; i--){
      printf("%d", hachi[i]);
    }
    printf("\n");
  }
  return 0;
}
