#include<iostream>
#include<cstring>

#define N 101
#define MOD 100007

using namespace std;

int m[N][N];
bool alphas[128][N];

int main(){
  int t, ti, n, i, j, k, d;
  char line[N], c;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> line;
    n = strlen(line);
    for(i = 0; i < 128; i++){
      for(j = 0; j <= n; j++){
	alphas[i][j] = false;
      }
    }
    for(i = 0; i < n; i++){
      alphas[line[i]][i] = true;
    }
    for(k = 0; k < n; k++){
      for(j = k; j < n; j++){
	i = j-k;
	if(i == j){
	  m[i][j] = 1;
	}else{
	  m[i][j] = 1+m[i][j-1];
	  c = line[j];
	  for(d = i; d < j; d++){
	    if(alphas[c][d]){
	      // cout << c << ": " << d << ", " << m[d+1][j-1] << endl;
	      m[i][j] = (m[i][j]+m[d+1][j-1]+1)%MOD;
	    }
	  }
	  m[i][j] %= MOD;
	}
      }
    }
    // for(i = 'a'; i < 'z'; i++){
    //   for(j = 0; j < n; j++){
    // 	cout << alphas[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    cout << "Case #" << ti << ": " << m[0][n-1] << endl;
    // for(i = 0; i < n; i++){
    //   for(j = 0; j < n; j++){
    // 	cout << m[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
}
