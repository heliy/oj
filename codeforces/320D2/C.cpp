#include<iostream>
#include<cstdio>

using namespace std;

double min(double a, double b){
  if(a < b){
    return a;
  }else{
    return b;
  }
}

double up(int a, int b){
  double ab;
  int k;
  ab = (a-b)/2.0;
  for(k = (int)ab/b+2; (ab/k) < b; k--)
    ;
  return ab/k;
}

double down(int a, int b){
  double ab;
  int k;
  ab = (a+b)/2.0;
  for(k = (int)ab/b+2; (ab/k) < b; k--)
    ;
  return ab/k;  
}

int main(){
  int a, b, x, k;
  cin >> a >> b;
  if(a < b){
    cout << -1 << endl;
  }else if(a == b){
    cout << b << endl;
  }else{
    printf("%.12f\n", min(up(a, b), down(a, b)));
  }
}
