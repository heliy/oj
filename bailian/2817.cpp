#include<stdio.h>

using namespace std;

int numb[51];
int temp[51];

int isok(int r){
  int i, j;
  for(i = 1; i <= 50; i++){
    temp[i] = numb[i];
  }
  for(i = 1; i <= 50; i++){
    while(temp[i]){
      j = r - i;
      if(temp[j] == 0){
	return 0;
      }else{
	temp[i]--;
	temp[j]--;
      }
    }
  }
  return 1;
}

int main(){
  int n, i, l, init;
  while(scanf("%d", &n) != EOF && n){
    init = 0;
    for(i = 1; i < 51; i++){
      numb[i] = 0;
    }
    for(i = 0; i < n; i++){
      scanf("%d", &l);
      numb[i]++;
      if(l > init){
	init = l;
      } 
    }
    while(true){
    printf("%d\n", init);
      if(isok(init)){
	printf("%d\n", init);
	break;
      }
      init++;
    }
  }
}
