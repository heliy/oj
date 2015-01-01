#include<stdio.h>
#include<algorithm>

#define N 201

using namespace std;

int main(){
  char string[N];
  int len;
  while(scanf("%s", string) != EOF){
    for(len = 0; string[len] != '\0'; len++);
    sort(string, string+len);
    printf("%s\n", string);
  }
}
