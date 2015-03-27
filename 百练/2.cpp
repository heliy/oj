#include<iostream>
#include<cstdio>
#define N 800
using namespace std;

int fact[N];
int dits[10];

void multi(int n){
  int i;
  for(i = 0; i < N; i++){
    fact[i] *= n;
    if(n > 0 && fact[i-1] > 9){
      fact[i] += fact[i-1]/10;
      fact[i-1] %= 10;
    }
  }
}

int main(){
  int n;
  while(cin >> n && n){
    int i, k;
    fact[0] = 1;
    for(i = 1; i < N; i++){
      fact[i] = 0;
    }
    for(i = 2; i <= n; i++){
      multi(i);
    }
    for(i = 0; i < 10; i++){
      dits[i] = 0;
    }
    for(i = N-1; i >= 0 && fact[i] == 0; i--);
    for(; i >= 0; i--){
      dits[fact[i]]++;
    }
    cout << n << "! --" << endl;
    for(i = 0; i < 5; i++){
      if(i == 0){
	cout << "   (0)";
      }else{
	cout << "    (" << i << ")";
      }
      printf("%5d", dits[i]);
    }
    cout << endl;
    for(; i < 10; i++){
      if(i == 5){
	cout << "   (5)";
      }else{
	cout << "    (" << i << ")";
      }
      printf("%5d", dits[i]);
    }
    cout << endl;
  }
  return 0;
}
