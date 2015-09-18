#include<iostream>

using namespace std;

int main(){
  int a, b, n, i, s, bs;
  cin >> bs;
  b = 0;
  while(cin >> n){
    if(b){
      cout << endl;
    }
    b++;
    if(n == 0){
      break;
    }
    for(i = s = 0; i < n; i++){
      cin >> a;
      s += a;
    }
    cout << s << endl;
  }
}
