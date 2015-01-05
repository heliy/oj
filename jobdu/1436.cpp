#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main(){
  int l, n, i;
  int blocks[600];
  while(scanf("%d %d", &l, &n) != EOF){
    for(i = 0; i < n; i++){
      scanf("%d", blocks+i);
    }
    sort(blocks, blocks+n);
    int curr = 0, num = 0;
    for(i = n - 1; i >= 0; i--){
      curr += blocks[i];
      num++;
      if(curr >= l){
	break;
      }
    }
    if(curr >= l){
      printf("%d\n", num);
    }else{
      printf("impossible\n");
    }
  }
}
