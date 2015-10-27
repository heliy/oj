#include<stdio.h>
#include<string.h>
using namespace std;

char str1[101], str2[101];

void format(char *str){
  int i, j;
  for(i = j = 0; str[i] != '\0' && str[i] != '\n'; i++){
    if(str[i] != ' '){
      if(str[i] >= 'a' && str[i] <= 'z'){
	str[j++] = str[i] - 'a' + 'A';
      }else{
	str[j++] = str[i];
      }
    }
  }
  str[j] = '\0';
}

int main(){
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    fgets(str1, 101, stdin);
    fgets(str1, 101, stdin);
    fgets(str2, 101, stdin);
    format(str1);
    format(str2);
    if(strcmp(str1, str2) == 0){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}
