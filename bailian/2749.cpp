#include<iostream>
#include<cmath>

using namespace std;

int sp(int k, int a){
  int count = 1;
  if(k*k > a){
    return 1;
  }
  if(k*k == a){
    return 2;
  }
  for(; k*k <= a; k++){
    if(a%k == 0){
      count += sp(k, a/k);
    }
  }
  return count;
}


int main(){
  int a;
  cin >> a;
  while(cin >> a){
    cout << sp(2, a) << endl;
  }
}
