#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 500001
#define N 1001
#define M(a, b) ((a)>(b)?(a):(b))

using namespace std;

bool isprime[MAX];
void setprime(){
  int i, j;
  isprime[1] = false;
  for(i = 2; i < MAX; i++){
    isprime[i] = true;
  }
  for(i = 1; i < MAX; i++){
    if(isprime[i]){
      for(j = i*2; j < MAX; j += i){
	isprime[j] = false;
      }
    }
  }
}

int dits[N];
int hass[N];

int hasin(int l, int begin, int n){
  //  cout << begin << ":\n";
  if(begin == n){
    return l;
  }
  int j, k, b = dits[begin];
  bool in = true;
  for(j = 0; j < l; j++){
    k = b/hass[j];
    if(isprime[k] && (k*hass[j] == b)){
      in = false;
      break;
    }
    if(!in){
      break;
    }
  }
  k = 0;
  if(in){
    hass[l++] = b;
    k = hasin(l, begin+1, n);
    l--;
  }
  l = M(k, hasin(l, begin+1, n));
  return l;
}

int main(){
  setprime();
  int t, ti, n, i, j, k;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n;
    for(i = 0; i < n; i++){
      scanf("%d", &dits[i]);
    }
    sort(dits, dits+n);
    cout << "Case #" << ti << ": " << hasin(0, 0, n) << endl;
  }
}
