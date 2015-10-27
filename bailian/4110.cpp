#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct candy{
  int v;
  int w;
  double ei;
};

bool cmp(struct candy c1, struct candy c2){
  return c1.ei > c2.ei;
}

struct candy candys[100];

int main(){
  int n, m, v, w, i;
  double s = 0;
  cin >> n >> m;
  for(i = 0; i < n; i++){
    cin >> v >> w;
    candys[i].v = v;
    candys[i].w = w;
    candys[i].ei = (double)v/w;
  }
  sort(candys, candys+n, cmp);
  i = 0;
  while(i < n){
    if(candys[i].w >= m){
      s += candys[i].ei*m;
      break;
    }else{
      s += candys[i].v;
      m -= candys[i].w;
    }
    i++;
  }
  printf("%.1f\n", s);
}
