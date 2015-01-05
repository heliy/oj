#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct room{
  int beans;
  int require;
  int trade;
  float get;
  float ratio;
};

void sets(struct room *r, int m){
  if(r->require == 0){
    r->ratio = 0;
    r->get = 0;
  }else{
    r->trade = m > r->require ? r->require : m;
    r->get = r->beans * (r->trade / (float)r->require);
    r->ratio = r-> get / r->trade; 
  }
}

struct room house[1001];

int main(){
  int m, n, get;
  while(scanf("%d %d", &m, &n) != EOF){
    if(m == -1){
      break;
    }
    int i;
    float total_get = 0;
    for(i = 0; i < n; i++){
      scanf("%d %d", &house[i].beans, &house[i].require);
    }
    while(m > 0){
      int max_i = 0;
      for(i = 0; i < n; i++){
	sets(&house[i], m);
	if(house[i].ratio > house[max_i].ratio){
	  max_i = i;
	}
      }
      if(house[max_i].get == 0){
	break;
      }
      total_get += house[max_i].get;
      m -= house[max_i].trade;
      house[max_i].require = 0;
    }
    printf("%.3f\n", total_get);
  }
}
