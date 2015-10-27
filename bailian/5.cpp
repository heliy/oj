#include<iostream>
#include<cstring>
using namespace std;

char stack[100][75] = {
  "http://www.acm.org/",
};
int top = 0;
char line[100];

int main(){
  int i;
  for(i = 1; i < 100; i++){
    stack[i][0] = '\0';
  }
  while(cin >> line){
      // cout << line[0] << endl;
    if(line[0] == 'Q'){
      break;
    }else if(line[0] == 'V'){
      top++;
      cin >> stack[top];
      cout << stack[top] << endl;
    }else if(line[0] == 'B'){
      if(top <= 0){
	cout << "Ignored" << endl;
      }else{
	top--;
	cout << stack[top] << endl;
      }
    }else{
      if(strlen(stack[top+1]) == 0){
	cout << "Ignored" << endl;
      }else{
	top++;
	cout << stack[top] << endl;
      }
    }
  }
}
