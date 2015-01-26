#include<stdio.h>

#define N 32768 // 2**15

bool nums[N];
int primes[N];

int main(){
  int i, j, count = 0;
  for(i = 2; i < N; i++){
    nums[i] = true;
  }
  for(i = 2; i < N/2; i++){
    if(nums[i]){
      primes[count++] = i;
      for(j = i*2; j < N; j += i){
	nums[j] = false;
      }
    }
  }
  int n, k;
  while(scanf("%d", &n) != EOF && n != 0){
    k = 0;
    for(i = 0; i < count && primes[i] <= n/2; i++){
      if(nums[n-primes[i]]){
	k++;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}
