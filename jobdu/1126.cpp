#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
  int array[80], n, k, i, j;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &k);
    for(j = 0; j < k; j++){
      scanf("%d", array+j);
    }
    int flag = 0;
    if(array[0] != array[1]){
      printf("0");
      flag = 1;
    }
    for(j = 1; j < k - 1; j++){
      if((array[j - 1] < array[j] && array[j] > array[j + 1]) ||
	 (array[j - 1] > array[j] && array[j] < array[j + 1])){
	if(flag){
	  printf(" ");
	}
	printf("%d", j);
	flag = 1;
      }
    }
    if(array[k - 1] != array[k - 2]){
      if(flag){
	printf(" ");
      }
      printf("%d", j);      
      flag = 1;
    }
    printf("\n");
  }
}
