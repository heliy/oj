#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
  int p, e, i, d, n = 1;
  while(cin >> p >> e >> i >> d && p >= 0){
    int t;
    for(t = d+1; abs(t-p)%23 != 0; t++)
      ;
    for(; abs(t-e)%28 != 0; t += 23)
      ;
    for(; abs(t-i)%33 != 0; t += 23*28)
      ;
    cout << "Case " << n << ": the next triple peak occurs in " << t-d << " days." << endl;
    n++;
  }
}
