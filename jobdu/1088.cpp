#include<stdio.h>
#include<stdlib.h>

#define L 10001
using namespace std;


int main(){
  int road[L];
  int l, m, i, j;
  while(scanf("%d %d", &l, &m) != EOF){
    for(i = 0; i <= l; i++){
      road[i] = 1;
    }
    int from, to;
    for(i = 0; i < m; i++){
      scanf("%d %d", &from, &to);
      for(j = from; j <= to; j++){
	road[j] = 0;
      }
    }
    int count;
    for(count = 0, i = 0; i <= l; i++){
      if(road[i] == 1){
	count++;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
