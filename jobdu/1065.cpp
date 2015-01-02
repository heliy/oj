#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
  int h;
  while(scanf("%d", &h) != EOF){
    int i,j;
    for(i = 0; i < h; i++){
      for(j = 1; j < h - i; j++){
	printf("  ");
      }
      for(j = 0; j < i; j++){
	printf("**");
      }
      for(j = 0; j < h; j++){
	printf("*");
      }
      printf("\n");
    }
  }
  return 0;
}
