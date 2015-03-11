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

  mi = 1; mj = sum/K; m = (mi+mj)/2;
  int test = isok(m);
  while(test != 0){
    if(test < 0){
      mj = m-1;
    }else{
      mi = m+1;
    }
    m = (mi+mj)/2;
    test = isok(m);
  }
  printf("%.2f\n", (double)m/100);
  return 0;
}
