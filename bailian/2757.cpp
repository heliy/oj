#include<iostream>
#define N 1010

using namespace std;

int a[N];
int c[N];

int main(){
  int n, i, j, m;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> a[i];
  }
  c[0] = 1;
  for(i = 1; i < n; i++){
    m = 0;
    for(j = 0; j < i; j++){
      if(a[i] > a[j] && c[j] > m){
	m = c[j];
      }
    }
    c[i] = m+1;
  }
  m = 0;
  for(i = 0; i < n; i++){
    if(c[i] > m){
      m = c[i];
    }
  }
  cout << m << endl;
}
