#include<cstdio>
#include<iostream>
#define N 10001

using namespace std;

int par[N];
int mid[N];

int main(){
  int min = N, max = 0;
  int a, b, i;
  cin >> i;
  while(cin >> a >> b){
    if(a < min){
      min = a;
    }
    if(b > max){
      max = b;
    }
    for(i = a; i < b; i++){
      par[i] = mid[i] = -1;
    }
    par[i] = -1;
  }
  for(i = min; i < max; i++){
    if(par[i] != -1 || mid[i] != -1){
      cout << "no\n";
      return 0;
    }
  }
  cout << min << " " << max << endl;
}
