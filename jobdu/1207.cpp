#include<stdio.h>
#include<math.h>

using namespace std;

bool is_prime(int k){
  int i, limit = sqrt(k) + 1;
  for(i = 2; i < limit; i++){
    if(k%i == 0){
      return false;
    }
  }
  return true;
}

int divide(int k){
  if(k == 1){
    return 0;
  }
  if(is_prime(k)){
    return 1;
  }
  int i, limit = k/2;
  for(i = 2; i <= limit; i++){
    if(k%i == 0){
      break;
    }
  }
  return divide(i) + divide(k/i);
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    printf("%d\n", divide(n));
  }
}
