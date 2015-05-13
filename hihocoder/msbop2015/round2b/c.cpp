#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 101

using namespace std;

int mazs[N][N];
int genders[N];

long long degree(int n){
  int i, j;
  long long c = 0;
  for(i = 1; i <= n; i++){
    for(j = i+1; j <= n; j++){
      if(genders[i]+genders[j] == 1){
	c += mazs[i][j];
      }
    }
  }
  return c;
}


int main(){
  int t, ti, n, m, q, x, y, z, i, j;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n >> m >> q;
    for(i = 1; i <= n; i++){
      scanf("%d", &genders[i]);
    }
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
	mazs[i][j] = 0;
      }
    }
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &x, &y, &z);
      mazs[x][y] = z;
      mazs[y][x] = z;
    }
    cout << "Case #" << ti << ":\n";
    for(i = 0; i < q; i++){
      scanf("%d", &j);
      if(j == 3){
	cout << degree(n) << endl;
      }else if(j == 2){
	scanf("%d %d %d", &x, &y, &z);
	mazs[x][y] = z;
	mazs[y][x] = z;
      }else if(j == 1){
	scanf("%d", &x);
	genders[x] = 1-genders[x];
      }
    }
  }
}
