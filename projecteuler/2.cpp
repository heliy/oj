#include<iostream>

using namespace std;

// 4613732


int main(){
  unsigned long long sum, a, b, f, t;
  a = 1;
  b = 1;
  sum = 0;
  while((f = a + b) <= 4000000){
    if(f%2 == 0){
      sum += f;
    }
    a = b;
    b = f;
  }
  cout << sum << endl;
}
