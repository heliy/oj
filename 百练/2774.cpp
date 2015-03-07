#include<iostream>

using namespace std;

int trape[10001];

int main(){
  int n, k, ni, i, max = 0;
  cin >> n >> k;
  for(ni = 0; ni < n; ni++){
    cin >> trape[ni];
    if(trape[ni] > max){
      max = trape[ni];
    }
  }
  while(max > 0){
    int count = 0;
    for(i = 0; i < n; i++){
      count += trape[i]/max;
    }
    if(count >= k){
      break;
    }
    max--;
  }
  cout << max << endl;
}
