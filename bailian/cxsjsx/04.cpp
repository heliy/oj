#include<iostream>

using namespace std;

bool isleap(int y){
  if((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0 && y % 3200 != 0)){
    return true;
  }else{
    return false;
  }
}

int main(){
  int y;
  cin >> y;
  if(isleap(y)){
    cout << "Y\n";
  }else{
    cout << "N\n";
  }
}
