#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  int i, n, s, t;
  cin >> n;
  for(i = s = 0; i < n; i++){
    cin >> t;
    s += t;
  }
  printf("%.2f\n", ((double)s)/n);
}
