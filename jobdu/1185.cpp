#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

#define N 1001

using namespace std;

int main(){
  int array[N];
  int n, i, max_index = -1, t, max = -1;
  while(scanf("%d", &n) != EOF){
    max_index = -1;
    max = -1;
    for(i = 0;i < n; i++){
      scanf("%d", &t);
      array[i] = t;
      if(t > max){
	max_index = i;
	max = t;
      }
    }
    for(i = max_index + 1; i < n; i++){
      array[i-1] = array[i];
    }
    if(n == 1){
      printf("%d\n-1\n", max);
    }else{
      sort(array, array + n - 1);
      printf("%d\n", max);
      for(i = 0; i < n - 1; i++){
        printf("%d",array[i]);
        if(i != n-2){
          printf(" ");
        }
      }
      printf("\n");
    }
  }
}
