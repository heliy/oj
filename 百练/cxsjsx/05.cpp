#include<iostream>

#define N 30000
using namespace std;

int main(){
  int p, e, i, d, n = 0;
  while(cin >> p >> e >> i >> d){
    if(p == -1){
      break;
    }
    n++;
    int t;
    for(t = d+1; t <= N; t++){
      if((t-p)%23 == 0){
	break;
      }
    }
    for(; t <= N; t += 23){
      if((t-e)%28 == 0){
	break;
      }
    }
    for(; t <= N; t += 23*28){
      if((t-i)%33 == 0){
	break;
      }
    }
    cout << "Case " << n << ": the next triple peak occurs in " << (t-d) << " days.\n";
  }
}
