#include<iostream>

using namespace std;

int min(int m, int n){
  if(n == 1){
    return 1;
  }
  if(m == 0){   // 必须是0
    return 1;
  }
  if(n > m){
    return min(m, m);
  }
  return min(m, n-1) + min(m-n, n);
}

int main(){
  int n, i;
  int a, b;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> a >> b;
    cout << min(a, b) << endl;
  }
  return 0;
}
