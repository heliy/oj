#include<iostream>

using namespace std;

int main(){
  int k, a[3] = {0, 0, 0}, ki, t;
  cin >> k;
  for(ki = 0; ki < k; ki++){
    cin >> t;
    switch(t){
    case 1: a[0]++; break;
    case 5: a[1]++; break;
    case 10: a[2]++; break;
    default: break;
    }
  }
  cout << a[0] << endl << a[1] << endl << a[2] << endl;
}
