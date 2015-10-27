#include<iostream>
#define N 10000

using namespace std;

int days[1+N];

int pro(){
  int i, k, j;
  days[1] = 1;
  for(i = 2, k = 2, j = 0; i <= N; i++, j++){
    if(j == k){
      k++;
      j = 0;
    }
    days[i] += (days[i-1]+k);
  }
}

int main(){
  pro();
  int i;
  while(cin >> i && i){
    cout << i << " " << days[i] << endl;
  }
}
