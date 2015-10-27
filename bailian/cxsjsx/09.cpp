#include<iostream>

using namespace std;

int med(int m, int n){
  if(n == 1 || m == 0){
    return 1;
  }else if(n > m){
    return med(m, m);
  }else{
    return med(m, n-1) + med(m-n, n);
  } 
}

int main(){
  int t, ti, m, n, c;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> m >> n;
    cout << med(m, n) << endl;
  }
}
