#include<stdio.h>

using namespace std;

int main(){
  int minx, miny, maxx, maxy;
  int n, i, j, c;
  scanf("%d", &n);
  minx = miny = n-1;
  maxx = maxy = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      scanf("%d", &c);
      if(c == 0){
	if(i < minx){
	  minx = i;
	}
	if(i > maxx){
	  maxx = i;
	}
	if(j < miny){
	  miny = j;
	}
	if(j > maxy){
	  maxy = j;
	}
      }
    }
  }
  if(maxx == minx || maxy == miny){
    printf("0\n");
  }else{
    printf("%d\n", (maxx-minx-1)*(maxy-miny-1));
  }
  return 1;
}
