#include<iostream>
#include<cmath>

using namespace std;

int main(){
  long long a,b,m;
  cin >> a;
  m = a + 1;
  while(true){
    m--;
    if(!((a*a+1)%m)){
      break;
    }
  }
  cout<< 2*a+m+(a*a+1)/m <<endl;
  return 0;
}
//105874
