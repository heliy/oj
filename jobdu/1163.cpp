#include<stdio.h>
#include<math.h>

int main(){
  bool nums[10001];
  int i, j;
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
    int first = 1;
    for(i = 11; i < n; i += 10){
      if(nums[i]){
	if(!first){
	  printf(" ");
	}
	printf("%d", i);
	first = 0;
      }
    }
    if(first){
      printf("-1");
    }
    printf("\n");
  }
  return 0;
}
