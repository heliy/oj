#include<iostream>
#define MIN(A, B) (A)>(B)?(B):(A)

using namespace std;

/* WA */

int min(int n, int k){
  if(n >= k){
    return n-k;
  }
  int left = n/2, i, j, m = 100000;
  for(i = 1; i <= left; i++){
    
  }
}

int main(){
  int n, k;
  cin >> n >> k;
  cout << min(n,k) << endl;
}
