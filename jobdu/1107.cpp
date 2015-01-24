#include<stdio.h>
#include<queue>

using namespace std;

int main(){
  int n, i, x;
  while(scanf("%d", &n) != EOF){
    if(n == 0){
      break;
    }
    priority_queue<int, vector<int>, greater<int> > Q;
    for(i = 0; i < n; i++){
      scanf("%d", &x);
      Q.push(x);
    }
    int wpl = 0;
    while(Q.size() > 1){
      int a, b;
      a = Q.top();
      Q.pop();
      b = Q.top();
      Q.pop();
      wpl += (a+b);
      Q.push(a+b);
    }
    printf("%d\n", wpl);
  }
  return 0;
}
