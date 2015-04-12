#include<iostream>
#include<cstdio>
#include<cmath>
#define MK 22
#define MOD 998244353

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
  unsigned long long max, min;
  if(a > b){
    max = a, min = b;
  }else{
    max = b, min = a;
  }
  if(min == 1){
    return 1;
  }else{
    return gcd(max%min, min);
  }
}

unsigned long long pows[MK];
int dits[MK];

unsigned long long multi(unsigned long long g, int k){
  int i, dits_len;
  pows[0] = g;
  for(i = 0; i < MK && k != 0; i++){
    dits[i] = k%2;
    k /= 2;
  }
  dits_len = i;
  for(i = 1; i < dits_len; i++){
    pows[i] = (pows[i-1]*pows[i-1])%MOD;
  }
  if(g == 2){
    return pows[dits_len];
  }
  unsigned long long r = 1;
  for(i = 0; i < dits_len; i++){
    if(dits[i] == 1){
      r = (r*pows[i])%MOD;
    }
  }  
  return r;
}

int main(){
  int t, ti, n, ni, i, k;
  unsigned long long g, r;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n >> k;
    cin >> g;
    for(ni = 0; ni < n; ni++){
      scanf("%d", &i);
      g = gcd(g, i);
    }
    g = multi(g, k);
    r = (multi(2, n)-1)%MOD;
    g = (g*r)%MOD;
    cout << r << endl;
  }
}
