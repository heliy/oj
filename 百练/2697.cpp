#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double f(double x, double a){
  return x*x*x + x + a;
}

int main(){
  int n, ni;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    double a, e ,r;
    cin >> a >> e;
    double x1 = -a, x2 = 0, x;
    do{
      x = (x2 + x1)/2;
      r = f(x, a);
      if((x2-x1) < e || r == 0){
	break;
      }else if(r > 0){
	x2 = x;
      }else{
	x1 = x;
      }
    }while(true);
    printf("%.6f %.6f\n", x, r);
  }
  return 0;
}
