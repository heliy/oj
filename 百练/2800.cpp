#include<stdio.h>

using namespace std;

char line[90];
int count[26];

int main(){
  int i;
  for(i = 0; i < 26; i++){
    count[i] = 0;
  }
  while(scanf("%s", line) != EOF){
    for(i = 0; line[i] != '\0'; i++){
      if(line[i] >= 'A' || line[i] <= 'Z'){
	count[line[i] - 'A']++;
      }
    }
  }
  int max = 0;
  for(i = 0; i < 26; i++){
    if(count[i] > max){
      max = count[i];
    }
  }
  while(max != 0){
    for(i = 0; i < 26; i++){
      if(count[i] >= max){
	printf("*");
      }else{
	printf(" ");
      }
      if(i < 25){
	printf(" ");
      }
    }
    max--;
    printf("\n");
  }
  for(i = 0; i < 25; i++){
    printf("%c ", 'A' + i);
  }
  printf("Z\n");
}
