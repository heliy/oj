#include<iostream>

using namespace std;

/* AC */

int main(){
  int a1, h1, a2, h2, t, ti;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> a1 >> h1 >> a2 >> h2;
    if(a1 == 0){
      cout << "Invalid" << endl;
    }else{
      h1 -= a2;
      h2 -= a1;
      if(h1 <= 0){
	cout << "Discard ";
      }else{
	cout << a1 << " " << h1 << " ";
      }
      if(h2 <= 0){
	cout << "Discard" << endl;
      }else{
        cout << a2 << " " << h2 << endl;
      }
    }
  }
}
