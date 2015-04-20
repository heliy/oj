#include<cstdio>
#include<iostream>
#include<cmath>
#define L 1001
#define MAX 99999999999999999

using namespace std;

int as[L][2];
int bs[L][2];

int n, m, a, b;
int e, f;
unsigned long long mincost;

unsigned long long costs(int x, int y){
  if(x < 1 || x > n || y < 1 || y > n){
    return MAX;
  }
  int i, m = L, k;
  unsigned long long c = 0;
  for(i = 0; i < a; i++){
    c += pow(x-as[i][0], 2)+pow(y-as[i][1], 2);
  }
  for(i = 0; i < b; i++){
    k = abs(x-bs[i][0]) + abs(y-bs[i][1]);
    if(k < m){
      m = k;
    }
  }
  if(b > 0){
    c += m;
  }
  return c;
}

void search(int x, int y){
  int sx, sy, mini, minj, i, j;
  unsigned long long c, min;
  min = MAX;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      sx = x+(i-1);
      sy = y+(j-1);
      c = costs(sx, sy);
      if(c < min){
	min = c;
	mini = sx;
	minj = sy;
      }
    }
  }
  // cout << x << ", " << y << ": " << mini << ", " << minj << ": " << min << endl;
  if(mini == x && minj == y){
    e = x;
    f = y;
    mincost = min;
  }else{
    search(mini, minj);
  }
}

int main(){
  int t, ti, i, j;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n >> m >> a >> b;
    for(i = 0; i < a; i++){
      scanf("%d %d", &as[i][0], &as[i][1]);
    }
    for(i = 0; i < b; i++){
      scanf("%d %d", &bs[i][0], &bs[i][1]);
    }
    search(n/2, m/2);
    cout << "Case #" << ti << ": " << mincost << endl;
  }
}
