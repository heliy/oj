#include<iostream>
#include<cstdio>
#define N 100002

using namespace std;

/* TLE */

int groups[N];
bool algets[N];
int to[N][2];

int main(){
  int n, ni, q, qi, l, r, i, j, p1, p2, id, another;
  cin >> n >> q;
  for(ni = 1; ni <= n; ni++){
    to[ni][0] = to[ni][1] = -1;
  }
  for(ni = 1; ni < n; ni++){
    scanf("%d %d", &p1, &p2);
    if(to[p1][0] == -1){
      to[p1][0] = p2;
    }else{
      to[p1][1] = p2;
    }
    if(to[p2][0] == -1){
      to[p2][0] = p1;
    }else{
      to[p2][1] = p2;
    }
  }
  for(qi = 0; qi < q; qi++){
    scanf("%d %d", &l, &r);
    for(i = l; i <= r; i++){
      groups[i] = i;
    }
    for(i = l; i <= r; i++){
      groups[to[i][0]] = groups[i];
      if(to[i][1] > 0){
	groups[to[i][1]] = groups[i];
      }
    }
    for(i = l; i <= r; i++){
      algets[i] = false;
    }
    int c = 0;
    for(i = l; i <= r; i++){
      if(!algets[groups[i]]){
  	c++;
  	algets[groups[i]] = true;
      }
    }
    printf("%d\n", c);
  }
}
