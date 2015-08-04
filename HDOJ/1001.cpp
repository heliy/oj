/* AC */

#include<iostream>

using namespace std;

int main(){
  long long n;
  while(cin >> n){
    n = ((n%2 == 0)?((1+n)*(n/2)):((n)*((n-1)/2)+n));
    cout << n << endl << endl;
  }
}
