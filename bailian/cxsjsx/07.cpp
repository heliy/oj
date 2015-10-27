#include<iostream>
#include<cmath>

#define N 17
#define W 0
#define Y 1

using namespace std;

int n;
int wall[N][N];
int init[N][N];

void print(){
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      cout << wall[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void push(int i, int j){
  wall[i][j] = 1-wall[i][j];
  wall[i+1][j] = 1-wall[i+1][j];
  wall[i-1][j] = 1-wall[i-1][j];
  wall[i][j+1] = 1-wall[i][j+1];
  wall[i][j-1] = 1-wall[i][j-1];
}

int tab(int first){
  int count = 0, i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      wall[i][j] = init[i][j];
    }
  }
  for(i = 1; i <= n; i++){
    j = first%2;
    first /= 2;
    if(j == 1){
      count++;
      push(1, i);
    }
  }
  // print();
  for(i = 2; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(wall[i-1][j] == W){
	count++;
	push(i, j);
      }
    }
    // print();
  }
  for(i = 1; i <= n; i++){
    if(wall[n][i] == W){
      return -1;
    }
  }
  return count;
}

int main(){
  int t, ti, i, j;
  char c;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n;
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
	cin >> c;
	init[i][j] = (c == 'w') ? W : Y;
      }
    }
    j = n*n+1;
    int m = pow(2, n);
    for(i = 0; i < m; i++){
      int s = tab(i);
      j = (s >= 0 && j > s) ? s : j;
    }
    if(j == n*n+1){
      cout << "inf\n";
    }else{
      cout << j << "\n";
    }
  }
}
