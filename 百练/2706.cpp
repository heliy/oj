#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int tail[505];

int pw[22];
void big_pow(int p){
  if(p < 22){
    int i, j, m = pw[p];
    for(j = 0; j < 500; j++){
      tail[j] = tail[j] * m;
      if(j > 0 && tail[j-1] >= 10){
	tail[j] += tail[j-1]/10;
	tail[j-1] %= 10;
      }
    }
  //   printf("*%d\n", p);
  // for(i = 499; i >= 0; i--){
  //   printf("%d", tail[i]);
  // }
  // printf("\n");
    
  }else{
    while(p > 21){
      big_pow(21);
      p -= 21;
    }
  big_pow(p);
  }
}

int main(){
  tail[0] = 1;
  pw[0] = 1;
  int p, i;
  for(i = 1; i < 22; i++){
    pw[i] = pw[i-1]*2;
  }
  for(i = 1; i < 505; i++){
    tail[i] = 0;
  }
  scanf("%d", &p);
  printf("%d\n", (int)(p*log10(2))+1);
  big_pow(p);
  tail[0] -= 1;
  for(i = 499, p = 1 ; i >= 0; i--, p++){
    printf("%d", tail[i]);
    if(p%50 == 0){
      printf("\n");
    }
  }
}
