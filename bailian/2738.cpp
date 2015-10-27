#include<stdio.h>
#define LEN 102

using namespace std;



char line1[LEN];
char line2[LEN];

int float1[LEN*2];
int float2[LEN*2];

void tofloat(char* line, int* f){
  int i, j;
  for(i = 0; i < LEN*2; i++){
    f[i] = 0;
  }
  for(i = 0; line[i] != '.'; i++)
    ;
  for(j = 0; line[i + 1 + j] != '\0' && line[i + 1 + j] != '\n'; j++){
    f[LEN + j] = line[i+1+j] - '0';
  }
  for(j = -1; i+j >= 0; j--){
    // printf("%d: %c\n", i+j, line[i+j]);
    f[LEN+j] = line[i+j] - '0';
  }
}

int main(){
  int n, ni;
  scanf("%d", &n);
  for(ni = 0; ni < n; ni++){
    int i, j;
    fgets(line1, LEN, stdin);
    fgets(line1, LEN, stdin);
    fgets(line2, LEN, stdin);
    tofloat(line1, float1);
    tofloat(line2, float2);
    for(i = LEN*2-1; i >= 0; i--){
      float2[i] += float1[i];
      if(i < LEN*2-1 && float2[i+1] >= 10){
    	float2[i] += float2[i+1]/10;
    	float2[i+1] %= 10;
      }
    }
    for(i = 0; i < LEN && float2[i] == 0; i++)
      ;
    if(i == LEN){
      printf("0");
    }else{
      for(; i < LEN; i++){
    	printf("%d", float2[i]);
      }
    }
    printf(".");
    for(j = LEN*2-1; float2[j] == 0; j--)
      ;
    for(i = LEN; i <= j; i++){
      printf("%d", float2[i]);
    }
    printf("\n");
  }
}
