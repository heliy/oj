#include<iostream>

using namespace std;

int array[22];
int num = 0;
int sum = 0;
int t;

void select(int n, int m){
  if(m == 0){
    return;
  }
  int i;
  for(i = n-1; i >= 0; i--){
    sum += array[i];
    if(sum == t){
      num++;
    }else if(m > 1){
      select(i, m-1);
    }
    sum -= array[i];
  }
}

int main(){
  int n, i, j, k;
  cin >> n >> t;
  for(i = 0; i < n; i++){
    cin >> array[i];
  }
  select(n, n);
  cout << num << endl;
}
