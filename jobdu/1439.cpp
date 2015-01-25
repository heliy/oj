#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

long long nums[9999];

int main(){
  int n, m, j, i;
  long long k;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &m);
    for(j = 0; j < m; j++){
      scanf("%lld", nums+j);
    }
    k = nums[--j];
    for(j--; j >= 0; j--){
      k = k*nums[j]/gcd(k, nums[j]);
    }
    printf("%lld\n", k);
  }
  return 0;
}
