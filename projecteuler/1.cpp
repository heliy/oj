#include<iostream>
#define N 1000

// 233168

using namespace std;

bool array[N];

int main(){
  int i, s;
  for(i = 3; i < N; i += 3){
    array[i] = true;
  }
  for(i = 5; i < N; i += 5){
    array[i] = true;
  }
  for(s = i = 0; i < N; i++){
    if(array[i]){
      s += i;
    }
  }
  cout << s << endl;
}
