#include<iostream>
#include<cmath>

using namespace std;

int nums[10000];
int a[34];
int l = 0;
int n, k, m, s;

void add(long long sd){
  int i, kc, mc, mm;
  long long d = sd;
  kc = mc = mm = 1;
  for(i = n; i > 0; i--){
    a[i] = sd%2;
    sd /= 2;
  }
  for(i = 2; i <= n; i++){
    if(a[i] != a[i-1]){
      kc++;
      if(mm > mc){
	mc = mm;
      }
      mm = 1;
    }else{
      mm++;
      if(mm > mc){
	mc = mm;
      }
    }
    // cout << i << ": " << kc << endl;
  }
  if(kc == k && mc <= m){
    nums[++l] = d;
  }
}

int find(long long d){
  int i = 1, j = l, m = (1+l)/2;
  long long sd = d;
  for(d = 0, i = 1; sd > 0; i *= 2){
    d += i*(sd%10);
    sd /= 10;
  }
  i = 1, j = l, m = (1+l)/2;
  // cout << d << ":\n";
  while(nums[m] != d && i <= j){
        // cout << i << "," << j << "," << m << ":" << a[m] << ", ";
    if(nums[m] < d){
      i = m+1;
    }else{
      j = m-1;
    }
    m = (i+j)/2;
    // cout << m << endl;
  }
  if(nums[m] == d){
    return m;
  }else{
    return -1;
  }
}


int main(){
  cin >> n >> k >> m >> s;
  long long i, len, t;
  for(len = pow(2, n-1), i = 2; i <= (m+1); i++){
    len += pow(2, n-i);
  }
  len++;
  for(i = pow(2, n-1); i < len; i++){
    add(i);
  }
  cout << l << endl;
  while(cin >> t){
    cout << find(t)-1 << endl;
  }
  return 0;
}
