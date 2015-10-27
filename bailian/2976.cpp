#include<stdio.h>

using namespace std;

char s[100001], t[100001];

int main(){
  while(scanf("%s %s", s, t) != EOF){
    int i, j = 0;
    for(i = 0; t[i] != '\0' && t[i] != '\n'; i++){
      if(s[j] == t[i]){
	j++;
      }
    }
    if(s[j] == '\0' || s[j] == '\n'){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  return 0;
}
