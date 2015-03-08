#include<iostream>
#define N 25

using namespace std;

bool canstep[N*2][N];

int plans(int i, int j, int n){
  if(!canstep[i][j]){
    return 0;
  }
  if(n == 0){
    return 1;
  }
  canstep[i][j] = false;
  int s = 0;
  n--;
  s += plans(i-1, j, n);
  s += plans(i+1, j, n);
  s += plans(i, j+1, n);
  canstep[i][j] = true;
  return s;
}

int main(){
  int n;
  while(cin >> n){
    int i, j;
    for(i = 0; i < N*2; i++){
      for(j = 0; j < N; j++){
	canstep[i][j] = true;
      }
    }
    cout << plans(N, 0, n) << endl;
  }  
}
