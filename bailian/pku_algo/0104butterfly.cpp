#include<iostream>
#include<cstdio>
#define N 1001

using namespace std;

int diff[N][N];
int indexes[N];

int root(int i){
  if(indexes[i] != i){
    indexes[i] = root(indexes[i]);
  }
  return indexes[i];
}

void uni(int a, int b){
  int r = root(a);
  int s = root(b);
  if(r < s){
    indexes[s] = r;
  }else if(r > s){
    indexes[r] = s;
  }
}

int main(){
  int n, m, i, j, a, b;
  while(cin >> n >> m){
    for(i = 0; i < n; i++){
      indexes[i] = i;
      for(j = 0; j < n; j++){
	diff[i][j] = 0;
      }
    }
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &a, &b, &j);
      if(j == 1){
	diff[a][b] = diff[b][a] = 1;
      }else{
	uni(a, b);
      }
    }
    bool flag = false;
    for(i = 0; i < n; i++){
      for(j = i+1; j < n; j++){
	if(diff[i][j]){
	  if(root(i) == root(j)){
	    // cout << i << ", " << j << ": " << root(i) << endl;
	    flag = true;
	    break;
	  }
	}
      }
      if(flag){
	break;
      }
    }
    if(flag){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
}
