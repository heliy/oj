#include<iostream>
#include<stdio.h>
#define MAX 21252

using namespace std;

int main(){
  int p, e, i, d ,n = 1, k;
  while(cin >> p >> e >> i >> d){
    if(d == -1){
      break;
    }
    for(k = d+1; k < MAX && (k-p)%23 != 0; k++)
      ;
    for(; k < MAX && (k-e)%28 != 0; k+= 23)
      ;
    for(; k < MAX && (k-i)%33 != 0; k+=(23*28))
      ;

    printf("Case %d: the next triple peak occurs in %d days.\n", n, k-d);
    n++;
  }
}
