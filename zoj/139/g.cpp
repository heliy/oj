#include<iostream>
#include<cmath>
#include<cstdio>
#define PI 3.1415926535

using namespace std;

int main(){
  int t, ti, r, h, d;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> r >> h >> d;
    double volume, surface;
    surface = PI*(r*r*2+(r+d)*(r+d)*h+d*d*2+4*d*r);
    cout << surface << endl;
  }
}
