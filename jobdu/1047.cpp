#include<stdio.h>
#include<math.h>

using namespace std;

bool is_prime(int n){
  if(n <= 1){
    return false;
  }
  int i, s = (int)sqrt(n) + 1;
  for(i = 2; i < s; i++){
    if(n%i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    if(is_prime(n)){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }
  return 0;
}
