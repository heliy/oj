#include<stdio.h>
#include<stdlib.h>
using namespace std;


int king(int x, int y){
  return (x > y)? x : y; 
}

int queen(int x, int y){
  if(x == 0 && y == 0){
    return 0;
  }if(x == y || x == 0 || y == 0){
    return 1;
  }
  return 2;
}

int kuruma(int x, int y){
  if(x == 0 && y == 0){
    return 0;
  }else if(x == 0){
    return 1;
  }else if(y == 0){
    return 1;
  }else{
    return 2;
  }
}

int nusi(int x, int y){
  if(abs(x - y)%2 == 0){
    if(x == 0 && y == 0){
      return 0;
    }else if(x == y){
      return 1;
    }else{
      return 2;
    }
  }
  else return -1;
}

int main(){
  int n, i;
  char line[6];
  scanf("%d", &n);
  fgets(line, 6, stdin);
  for(i = 0; i < n; i++){
    fgets(line, 6, stdin);
    if(line[0] == '\n'){
      fgets(line, 6, stdin);      
    }
    int x = abs(line[0] - line[3]);
    int y = abs(line[1] - line[4]);
    printf("%d %d %d ", king(x, y), queen(x, y), kuruma(x,y));
    if(nusi(x,y) >= 0){
      printf("%d\n", nusi(x,y));
    }else{
      printf("Inf\n");
    }
  }
}
