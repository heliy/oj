#include<stdio.h>

using namespace std;

char array[35];
int dec[35];
int bin[300];

int divide(){
  int i, mae, r, sub;
  if(dec[0] == 0 || dec[0] == 1){
    sub = 1;
  }else{
    sub = 0;
  }
  i = mae = 0;
  while(dec[i] != -1){
    r =  (mae*10 + dec[i]);
    mae = r%2;
    dec[i - sub] = r/2;
    i++;
  }
  dec[i-sub] = -1;
  return mae;
}

int main(){
  while(scanf("%s", array) != EOF){
    int i;
    for(i = 0; array[i] != '\0'; i++){
      dec[i] = array[i] - '0';
    }
    dec[i] = -1;
    i = 0;
    do{
      bin[i] = divide();
      i++;
    }while(dec[0] != -1);
    for(i--; i >= 0; i--){
      printf("%d", bin[i]);
    }
    printf("\n");
  }
}
