#include<iostream>

#define MAX(A, B) ((A)>(B)?(A):(B))

using namespace std;

int kags[30];
int f[30];

int main(){
  int n, i, j, m;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> kags[i];
  }
  f[0] = 1;
  for(i = 1; i < n; i++){
    m = 0;
    for(j = 0; j < i; j++){
      if(kags[j] >= kags[i]){
	m = MAX(m, f[j]+1);
      }
    }
    f[i] = MAX(m, 1);
  }
  m = 0;
  for(i = 0; i < n; i++){
    m = MAX(m, f[i]);
  }
  cout << m << endl;
}
