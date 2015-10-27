#include<stdio.h>
#include<string.h>
#define MAX_LEN 200

unsigned an1[MAX_LEN+10];
unsigned an2[MAX_LEN+10];
unsigned result[MAX_LEN*2+10];
char line1[MAX_LEN+10];
char line2[MAX_LEN+10];

int main(){
  fgets(line1, MAX_LEN, stdin);
  fgets(line2, MAX_LEN, stdin);
  int i, j;
  memset(an1, 0, sizeof(an1));
  memset(an2, 0, sizeof(an2));
  memset(result, 0, sizeof(result));

  int len1 = strlen(line1);
  for(j = 0, i = len1-1; i >= 0; i--,j++){
    an1[j] = line1[i] - '0';
  }
  int len2 = strlen(line2);
  for(j = 0, i = len2-1; i >= 0; i--,j++){
    an2[j] = line2[i] - '0';
  }

  for(i = 0; i < len2; i++){
    for(j = 0; j < len1; j++){
      result[i+j] += an2[i]*an1[j];
    }
  }

  for(i = 0; i < MAX_LEN*2; i++){
    if(result[i] >= 10){
      result[i+1] += result[i]/10;
      result[i] %= 10;
    }
  }

  bool bso = false;
  for(i = MAX_LEN*2; i >= 0; i--){
    if(bso){
      printf("%d", result[i]);
    }else if(result[i]){
      printf("%d", result[i]);
      bso = true;
    }
  }
  if(!bso){
    printf("0");
  }
  printf("\n");
}
