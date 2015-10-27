#include<cstdio>
#include<iostream>
#include<cstring>

#define N 110

using namespace std;

int sum[N];
int single[N];
char input[N];

int main(){
  int n, i;
  for(i = 0; i < N; i++){
    sum[i] = single[i] = 0;
  }
  while(scanf("%s", input) != EOF){
    if((input[1] == '\0' || input[1] == '\n') && input[0] == '0'){
      break;
    }
    n = strlen(input);
    for(i = 0; i < n; i++){
      single[i] = input[n-i-1]-'0';
    }
    for(; i < N; i++){
      single[i] = 0;
    }
    for(i = 0; i < N; i++){
      int s = sum[i]+single[i];
      sum[i] = s%10;
      sum[i+1] += s/10;
    }
  }
    for(i = N-1; i >= 0; i--){
      if(sum[i] != 0){
	break;
      }
    }
    while(i >= 0){
      printf("%d", sum[i--]);
    }
    cout << endl;
}
