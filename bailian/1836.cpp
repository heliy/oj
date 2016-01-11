#include<iostream>
#define MAX(A, B) ((A)>(B)?(A):(B))

using namespace std;

double heights[1001];
int mf[1001];
int nf[1001];

int main(){
  int n, i, j, k, m;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> heights[i];
  }
  mf[0] = 1;
  for(i = 1; i < n; i++){
    mf[i] = 1;
    for(k = 0; k < i; k++){
      if(heights[k] < heights[i] && mf[k]+1 > mf[i]){
	mf[i] = mf[k]+1;
      }
    }
  }
  nf[n-1] = 1;
  for(i = n-1; i >= 0; i--){
    nf[i] = 1;
    for(k = n-1; k > i; k--){
      if(heights[k] < heights[i] && nf[k]+1 > nf[i]){
	nf[i] = nf[k]+1;
      }
    }
  }
  m = 1;
  for(i = 0; i < n; i++){
    m = MAX(m, nf[i]+mf[i]-1);
    for(j = i+1; j < n; j++){
      m = MAX(m, mf[i]+nf[j]);
    }
  }
  cout << (n-m) << endl;
}
