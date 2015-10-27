#include<iostream>
#define A 0
#define B 1
#define N 100001
#define MIN(A, B) ((A)<(B)?(A):(B))
#define MAX(A, B) ((A)>(B)?(A):(B))

using namespace std;

int ds[N][2];
int cases[N];
int di;

void prase(int a, int n){
  int i, j;
  if(cases[a] >= 0){
    return;
  }
  for(i = 0; i < di; i++){
    if(ds[i][0] == a){
      prase(ds[i][1], n);
      if(ds[i][1] >= 0){
	cases[a] = 1-cases[i][1];
      }
    }else if(ds[i][1] == a){
      prase(ds[i][0], n);
      if(ds[i][0] > 0)
    }
  }
}


int main(){
  int t, n, m ,ti, i, mi, a, b;
  char c;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n >> m;
    di = 0;
    for(i = 1; i <= n; i++){
      cases[i] = -1;
    }
    cases[1] = A;
    for(mi = 0; mi < m; mi++){
      cin >> c >> a >> b;
      if(c == 'D'){
	if(cases[a] != -1){
	  cases[b] = 1-cases[a];
	}else if(cases[b] != -1){
	  cases[a] = 1-cases[b];
	}else{
  	  ds[di][0] = MIN(a, b);
	  ds[di][1] = MAX(a, b);
	  di++;
	}
      }
      if(c == 'A'){
	prase(a, n);
	prase(b, n);
	if(cases[a] < 0 || cases[b] < 0){
	  cout << "Not sure yet." << endl;
	}else if(cases[a] == cases[b]){
	  cout << "In the same gang." << endl;
	}else{
	  cout << "In different gangs." << endl;
	}
      }
    }
  }
}
