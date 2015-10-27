#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

unsigned long pus[10001];
int N, K, i, v;


int isok(int m){
  v = 0;
  for(i = N-1; i >=0 && pus[i] >= m; i--){
    v += pus[i]/m;
  }
  return v-K;
}

int main(){
  unsigned long sum = 0, m, mi, mj;
  double d;
  cin >> N >> K;
  for(i = 0; i < N; i++){
    cin >> d;
    pus[i] = (unsigned long)(d*100);
    sum += pus[i];
  }
  if(sum < K){
    cout << "0.00" << endl;
    return 0;
  }
  sort(pus, pus+N);

  for(m = (sum/K); m > 0; m -= 100){
    if(isok(m) >= )
  }
  for(m += 100,i = 0; i < 100 && m > 0; m--, i++){

  }
}
