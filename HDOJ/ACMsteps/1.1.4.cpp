#include<iostream>

using namespace std;

int main(){
  int a, b, n, i, s;
  while(cin >> n){
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
