#include<iostream>
#include<cstdio>
#include<algorithm>

#define N 1010


using namespace std;

struct tri{
  int x;
  int y;
  int w;
};

bool cmp(struct tri t1, struct tri t2){
  if(t1.x != t2.x){
    return(t1.x < t2.x);
  }
  return(t1.y < t2.y);
}

struct tri tris[N];

int main(){
  int t,ti, n, i;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n;
    for(i = 0; i < n; i++){
      scanf("%d %d %d", &tris[i].x, &tris[i].y, &tris[i].w);
    }

  }
}
