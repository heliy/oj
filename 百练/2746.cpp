#include<iostream>

using namespace std;

int a[301];

int main(){
  int n, m, i, k;
  while(cin >> n >> m){
    if(n == 0 && m == 0){
      break;
    }
    for(i = 0; i < n; i++){
      a[i] = i;
    }
    k = 0;
    while(n >= 1){
      k = (k+m-1)%n;
      for(i = k; i +1 < n; i++){
	a[i] = a[i + 1];
      }
      n--;
    }
    cout << a[0]+1 << '\n';
  }
  return 0;
}
