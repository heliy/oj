#include<stdio.h>

using namespace std;

int castle[50][50];
int isused[50][50];
int numbs[2500];

int max = 0;
int count = 1;

int m, n;

void take(int i, int j, bool isinit){
  if(i < 0 || j < 0 || i >= m || i >= n){
    return;
  }
  if(isused[i][j]){
    return;
  }
  isused[i][j] = count;
  numbs[count]++;
  if(numbs[count] > max){
    max = numbs[count];
  }
  if(castle[i][j]%2 == 1){ // 向西
    castle[i][j] -= 1;
  }else{
    take(i, j-1, false);    
  }
  if(castle[i][j]%4 == 2){ // 向北
    castle[i][j] -= 2;
  }else{
    take(i-1, j, false);    
  }
  if(castle[i][j]%8 == 4){ // 向东
    castle[i][j] -= 4;
  }else{
    take(i, j+1, false);    
  }
  if(castle[i][j] == 8){  // 向南
    ;
  }else{
    take(i+1, j, false);    
  }
  if(isinit){
    count++;
  }
}

int main(){
  int i, j;
  scanf("%d %d", &m, &n);
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      scanf("%d", &castle[i][j]);
      isused[i][j] = 0;
    }
  }
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      take(i, j, true);
    }
  }
  printf("%d\n%d\n", count-1, max);
}
