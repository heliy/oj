#include<stdio.h>
#define MAXL 10001

using namespace std;

int locs[MAXL];

int main(){
  int l, m, i, j, f, t, r;
  scanf("%d %d", &l, &m);
  for(i = 0; i <= l; i++){
    locs[i] = 1;
  }
  for(i = 0; i < m; i++){
    scanf("%d %d", &f, &t);
    for(j = f; j <= t; j++){
      locs[j] = 0;
    }
  }
  for(r = 0, i = 0; i <= l; i++){
    r += locs[i];
  }
  printf("%d\n", r);
}
