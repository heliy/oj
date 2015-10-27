#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
  long long x, y, m, n, L, step = 1;
  cin >> x >> y >> m >> n >> L;
  if(m%n == 0 || n%m == 0){
    cout << "Impossible" << endl;
    return 0;
  }
  while(true){
    x = (x+m)%L;
    y = (y+n)%L;
    // cout << x << "," << y << endl;
    if(x == y){
      cout << step << endl;
      return 0;
    }
    step++;
  }
}
