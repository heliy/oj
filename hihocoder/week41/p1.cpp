#include<iostream>
#include<cmath>
#define MOD 19999997
using namespace std;

int dits[32];
unsigned long long matmulti[32][4];

unsigned long long N[100000000];

int main(){
  int n, i, dits_len, k;
  unsigned long long a, b, c, d, A, B, C, D;
  cin >> n;
  N[0] = N[1] = 1;
  for(i = 2; i <= n; i++){
    N[i] = (N[i-1]+N[i-2]);
  }
  cout << N[n] << ", " << N[n]%MOD << endl;

  a = 0;
  b = c = d = 1;
  matmulti[0][0] = 0;
  matmulti[0][1] = 1;
  matmulti[0][2] = 1;
  matmulti[0][3] = 1;
  k = 0;
  for(i = 0; i < 32 && n != 0; i++){
    dits[i] = n%2;
    n /= 2;
  }
  dits_len = i;
  for(i = 1; i < dits_len; i++){
    matmulti[i][0] = ((a*a)%MOD+(b*c)%MOD)%MOD;
    matmulti[i][1] = ((a*b)%MOD+(b*d)%MOD)%MOD;
    matmulti[i][2] = ((a*c)%MOD+(c*d)%MOD)%MOD;
    matmulti[i][3] = ((b*c)%MOD+(d*d)%MOD)%MOD;
    a = matmulti[i][0];
    b = matmulti[i][1];
    c = matmulti[i][2];
    d = matmulti[i][3];
    cout << i << ": " << a << ", " << b << ", " << c << ", " << d << endl;
    cout << N[(unsigned int)pow(2, i)] << endl;

  }
  a = d = 1;
  b = c = 0;
  for(i = 0; i < dits_len; i++){
    if(dits[i] == 1){
      A = (a*matmulti[i][0]+b*matmulti[i][2]);
      B = (a*matmulti[i][1]+b*matmulti[i][3]);
      C = (c*matmulti[i][0]+d*matmulti[i][2]);
      D = (c*matmulti[i][1]+d*matmulti[i][3]);
      // A = ((a*matmulti[i][0])%MOD+(b*matmulti[i][2])%MOD)%MOD;
      // B = ((a*matmulti[i][1])%MOD+(b*matmulti[i][3])%MOD)%MOD;
      // C = ((c*matmulti[i][0])%MOD+(d*matmulti[i][2])%MOD)%MOD;
      // D = ((c*matmulti[i][1])%MOD+(d*matmulti[i][3])%MOD)%MOD;
      a = A, b = B, c = C, d = D;
      k += pow(2, i);
    }
    cout <<  i << ", " << dits[i] << ": " << a << ", " << b << ", " << c << ", " << d << endl;
    cout << i << ", " << k << ": " << N[k] << ", " << N[k]%MOD << endl;
  }
  cout << d%MOD << endl;
}
