#include<iostream>
#define N 20
using namespace std;

int w[N+1][N+1][N+1];

int main(){
  int i, j, k;
  for(i = 0; i <= N; i++){
    for(j = 0; j <= N; j++){
      for(k = 0; k <= N; k++){
        if(i*j*k == 0){
          w[i][j][k] = 1;
        }else if(i < j && j < k){
	  w[i][j][k] = w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
	}else{
	  w[i][j][k] = w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
	}
      }
    }
  }
  while(cin >> i >> j >> k){
    if(i == -1 && j == -1 && k == -1){
      break;
    }
    cout << "w(" << i << ", " << j << ", " << k << ") = ";
    if(i <= 0 || j <= 0 || k <= 0){
      cout << 1;
    }else if(i > N || j > N || k > N){
      cout << w[20][20][20];
    }else{
      cout << w[i][j][k];
    }
    cout << endl;
  }
}
