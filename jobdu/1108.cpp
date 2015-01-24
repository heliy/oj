#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

char line[100];

int main(){
  int n, i, is_first = 1;
  while(scanf("%d", &n) != EOF){
    if(n == 0){
      break;
    }
    if(!is_first){
      printf("\n");
    }
    is_first= 0;
    fgets(line, 100, stdin);
    
    stack<int> numbers;
    for(i = 0; i < n; i++){
      fgets(line, 100, stdin);
      if(line[0] == 'P'){
        numbers.push(atoi(line+2));
      }else if(line[0] == 'O'){
        if(!numbers.empty()){
    	  numbers.pop();
    	}
      }else{                    //line[0] == 'A'
    	if(numbers.empty()){
    	  printf("E\n");
    	}else{
    	  printf("%d\n", numbers.top());
    	}
      }
    }
  }
  return 0;
}
