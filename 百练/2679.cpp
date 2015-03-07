#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int k, m = 0, i;
  cin >> k;
  for(i = 1; i <= k ; i++){
    m += pow(i, 3);
  }
  cout << m << endl;
}
