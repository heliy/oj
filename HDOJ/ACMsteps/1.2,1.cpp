#include<iostream>

using namespace std;

int main(){
  int t, n, i, m, h;
  while(cin >> n){
    if(n == 0){
      break;
    }
    for(i = t = m = 0; i < n; i++){
      cin >> h;
      if(h > m){
	t += (h-m)*6;
      }else{
	t += (m-h)*4;
      }
      m = h;
      t += 5;
    }
    cout << t << endl;
  }
}
