#include<iostream>

using namespace std;

int step(int x, int y){
  if(x == y){
    if(x == 0){
      return 0;
    }else if(x == 1){
      return 1;
    }else{
      return step(x, y-2)+2;
    }
  }else if(x-y == 2){
    if(x%2 == 1){
      return step(x-1, y-1)+1;
    }else{
      return (x/2-1)*4+2;
    }
  }else{
    return -1;
  }
}

int main(){
  int n, x, y;
  cin >> n;
  while(cin >> x >> y){
    int c = step(x, y);
    if(c < 0){
      cout << "No Number";
    }else{
      cout << c;
    }
    cout << endl;
  }
}
