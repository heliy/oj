#include<iostream>

using namespace std;

int f[22];

int main(){
  int i, a;
  f[1] = f[2] = 1;
  for(i = 3; i < 22; i++){
    f[i] = f[i-1] + f[i-2];
  }
  cin >> a;
  while(cin >> a){
    cout << f[a] << endl;
  }
  return 0;
}
