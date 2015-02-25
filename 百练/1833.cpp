#include<iostream>
#include<algorithm>

using namespace std;

int cmp(int a, int b){
  return a-b;
}

int a[1024];

int main(){
  int m, n, i, k, mi;
  cin >> m;
  for(mi = 0; mi < m; mi++){
    cin >> n >> k;
    for(i = 1; i <= n; i++){
      cin >> a[i];
    }
    a[0] = 1025;
    while(k > 0){
      k--;
      int j, kk;
      for(j = n; j >= 1 && a[j-1] > a[j]; j--)
	;
      if(j >= 1){
	int larger = a[j];
	int idx = j;
	for(kk = j; kk <= n; kk++){
	  if(larger > a[kk] && a[kk] > a[j-1]){
	    larger = a[kk];
	    idx = kk;
	  }
	}
	a[idx] = a[j-1];
	a[j-1] = larger;
	sort(a+j, a+n+1, cmp);
      }else{
	for(j = 1; j <= n; j++){
	  a[j] = j;
	}
      }
    }
    for(i = 1; i <= n; i++){
      cout << a[i];
      if(i != n){
	cout << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
