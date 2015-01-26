#include<stdio.h>

#define N 250000

using namespace std;

bool nums[N];
int primes[N];

void primenum(){
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
}

int main(){
  int n;
  primenum();
  while(scanf("%d", &n) != EOF){
    printf("%d\n", primes[n-1]);
  }
  return 0;
}
