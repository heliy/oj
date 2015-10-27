#include<iostream>

using namespace std;

bool friends[101][100];


int main(){
  int c, ci, n, m, mi, k, ki, p1, p2, i, j;
  cin >> c;
  for(ci = 0; ci < c; ci++){
    cout << "Case " << ci+1 << ":" << endl;
    cin >> n >> m >> k;
    for(i = 0; i < 101; i++){
      for(j = 0; j < 101; j++){
	friends[i][j] = false;
      }
    }
    for(mi = 0; mi < m; mi++){
      cin >> p1 >> p2;
      friends[p1][p2] = true;
      friends[p2][p1] = true;
    }
    for(ki = 0; ki < k; ki++){
      cin >> p1 >> p2;
      j = 0;
      for(i = 1; i <= n; i++){
	if(friends[p1][i] && friends[p2][i]){
	  j++;
	}
      }
      cout << j << endl;
    }
  }
}
