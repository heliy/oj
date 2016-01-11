#include<iostream>

using namespace std;

int mat[501][501];
int subs[501];

int main(){
  int n, i, j, ki, kj, s;
  cin >> n;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cin >> mat[i][j];
    }
  }
  int max = 0;
  for(i = 0; i < n; i++){
    for(ki = 0; ki < n; ki++){
      subs[ki] = 0;
    }
    for(j = i; j < n; j++){
      for(ki = 0; ki < n; ki++){
	  subs[ki] += mat[j][ki];
      }
      for(s = 0, ki = 0; ki < n; ki++){
	s += subs[ki];
	if(s < 0){
	  s = 0;
	}else if(s > max){
	  max = s;
	}
      }
    }
  }
  cout << max << endl;
}
