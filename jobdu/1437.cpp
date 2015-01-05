#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct station{
  float price;
  int distance;
  //  int maxfar;
};

int cmp(struct station s1, struct station s2){
  return s1.distance < s2.distance;
}

int main(){
  int cmax, d, davg, n;
  struct station stations[501];
  while(scanf("%d %d %d %d", &cmax, &d, &davg, &n) != EOF){
    int i, maxsingle = cmax * davg;
    for(i = 0; i < n; i++){
      scanf("%f %d", &stations[i].price, &station[i].distance);
    }
    sort(stations, stations+n, cmp);
    int maxsofar = 0, last = 0, maxthis = 0, between;
    while(maxsofar <= d){
      for(i = last; i < n; i++){
	if(stations[i].distance - stations[last] > maxsingle){
	  i--;
	  break;
	}else if(stations[i].price < stations[last].price){
	  break;
	}
      }
      if(stations[i].price > stations[last] )
    }
  }
}
