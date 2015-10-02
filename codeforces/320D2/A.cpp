#include<iostream>
#include<cstdio>

using namespace std;

int bits[100];

int main(){
  int x, n = 0;
  cin >> x;
  while(x != 0){
    n += x%2;
    x /= 2;
  }
  cout << n << endl;
}
