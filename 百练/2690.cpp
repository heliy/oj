#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  char c;
  bool istrun = true;
  while(scanf("%c", &c) != EOF){
    if(c == ' ' || c == '\t' || c == '\r' || c == '\n'){
      istrun = true;
      cout << c;
    }else{
      if(istrun){
	if(c >= 'a' && c <= 'z'){
	  cout << (char)('A'+(c-'a'));
	}else{
	  cout << c;
	}
	istrun = false;
      }else{
	cout << c;
      }
    }
  }
}
