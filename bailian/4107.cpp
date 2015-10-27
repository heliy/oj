#include<iostream>

using namespace std;

bool isinclude(int p){
  while(p > 10){
    if(p%100 == 19){
      return true;
    }
    p /= 10;
  }
  return false;
}

int main(){
  int n, ni, p;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    cin >> p;
    if(p%19 == 0 || isinclude(p)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
