#include<stdio.h>
#include<stack>

using namespace std;

stack<int> S;

char str[101];
char ans[101];

int main(){
  while(scanf("%s", str) != EOF){
    int i;
    for(i = 0; str[i] != 0; i++){
      if(str[i] == '('){
	S.push(i);
	ans[i] = ' ';
      }else if(str[i] == ')'){
	if(!S.empty()){
	  S.pop();
	  ans[i] = ' ';
	}else{
	  ans[i] = '?';
	}
      }else{
	ans[i] = ' ';
      }
    }
    while(!S.empty()){
      ans[S.top()] = '$';
      S.pop(); 
    }
    ans[i] = 0;
    puts(str);
    puts(ans);
  }
  return 0;
}
