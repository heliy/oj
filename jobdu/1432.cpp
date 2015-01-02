#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
  char format[80][80];  //4分之一
  int n;
  char A, B;
  int mae = 0;
  while(scanf("%d %c %c", &n, &A, &B) != EOF){
    if(mae == 1){
      printf("\n");
    }
    if(n == 1){
      printf("%c\n", A);
      continue;
    }
    int mid = (n + 1) / 2;
    int i, j;
    char c;
    for(i = 0; i < mid; i++){
      if(i % 2 == 0){c = A;}
      else{c = B;}
      for(j = 0; j < i+1; j++){
	format[i][j] = c;
	format[j][i] = c;
      }
    }
    format[mid-1][mid-1] = ' ';
    for(i = mid - 1; i >= 0; i--){
      for(j = mid - 1; j >= 0; j--){
	printf("%c", format[i][j]);
      }
      for(j = 1; j < mid; j++){
	if(i == mid-1 && j == mid - 1){
	  continue;
	}
	printf("%c", format[i][j]);
      }
      printf("\n");
    }
    for(i = 1; i < mid; i++){
      for(j = mid -1; j >= 0; j--){
	printf("%c", format[i][j]);	
      }
      for(j = 1; j < mid; j++){
	if(i == mid-1 && j == mid - 1){
	  continue;
	}
	printf("%c", format[i][j]);
      }
      printf("\n");
    }
    mae = 1;
  }
  return 0;
}
