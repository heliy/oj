#include<stdio.h>
#include<math.h>

int main(){
  bool nums[10001];
  int i, j;
  nums[0] = false;
  nums[1] = false;
  for(i = 2; i < 10001; i++){
    nums[i] = true;
  }
  for(i = 2; i <= 5000; i++){
    if(nums[i] == true){
      for(j = i+i; j < 10001; j += i){
	nums[j] = false;
      }
    }
  }
  
  int n;
  while(scanf("%d", &n) != EOF){
    for(i = 1; i < n;)
  }
}
