#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<double> pq;

int main(){
  int n, i, c;
  double a, b;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> c;
    pq.push(c);
  }
  while(pq.size() > 1){
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    pq.push(2*sqrt(a*b));
  }
  printf("%.3f\n", pq.top());
}
