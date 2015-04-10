#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


int main(){
  int t, ti, i, j;
  unsigned long long n, m, r, mod;
  mod = 1000000007;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n;
    n %= mod;
    m = (n*(n+1)/2) % mod;
    r = (m*m*(m-2*n+2))%mod;
    cout << "Case " << ti << ": " << r << endl;
  }
}
