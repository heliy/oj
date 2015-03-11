#include<iostream>

using namespace std;

int m[27][27];
bool in[27];

int main(){
  int n, ni, l, i, j;
  char c;
  while(cin >> n && n != 0){
    for(i = 1; i < 27; i++){
      for(j = 1; j < 27; j++){
	m[i][j] = 0;
      }
    }
    int min = 101, mini, minj, sum;
    for(ni = 1; ni < n; ni++){
      cin >> c >> l;
      for(i = 0; i < l; i++){
	cin >> c >> j;
	m[ni][c-'A'+1] = j;
	m[c-'A'+1][ni] = j;
	if(j < min){
	  min = j;
	  mini = ni;
	  minj = c-'A'+1;
	}
      }
    }
    for(i = 1; i <= n; i++){
      in[i] = false;
    }
    sum = min;
    in[mini] = in[minj] = true;

    for(ni = 1; ni < n-1; ni++){
      min = 101;
      for(i = 1; i <= n; i++){
	if(!in[i]){
	  continue;
	}
	for(j = 1; j <= n; j++){
	  if(in[j]){
	    continue;
	  }

	  if(m[i][j] != 0 && m[i][j] < min){
	    min = m[i][j];
	    mini = i;
	    minj = j;
	  }
	}
      } 
      // cout << min << endl;
      sum += min;
      in[mini] = in[minj] = true;
   }

    cout << sum << endl;
  }
}
