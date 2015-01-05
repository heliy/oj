#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int materials[101];

int main(){
  int c, n, v, w, pi, i, j;
  scanf("%d", &c);
  for(i = 0; i < c; i++){
    scanf("%d %d %d", &n, &v, &w);
    for(j = 0; j < n; j++){
      scanf("%d", materials+j);
    }
    sort(materials, materials+n);
    int maxv = 0;
    float concentration = 0, next;
    for(j = 0; j < n; j++){
      next = (maxv*concentration + v*materials[j]) / (maxv + v);
      if(next > w){
	break;
      }else{
	concentration = next;
	maxv += v;
      }
    }
    printf("%d %1.2f\n", maxv, concentration / 100);
  }
}
