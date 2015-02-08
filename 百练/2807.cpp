#include<stdio.h>

using namespace std;

int main(){
  int array[101];
  int c, i, n;
  while(true){
    scanf("%d", &c);
    if(c == -1){
      break;
    }
    for(i = 1; i < 101; i++){
      array[i] = 0;
    }
    array[c] = 1;
    while(true){
      scanf("%d", &c);
      if(c == 0){
	break;
      }else{
	array[c] = 1;
      }
    }
    n = 0;
    for(i = 1; i < 50; i++){
      if(array[i] && array[i*2]){
	n++;
      }
    }
    printf("%d\n", n);
  }
}
