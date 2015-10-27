#include<iostream>
#include<cstdio>

using namespace std;

char reve[10000];
char word[10000];

int len = 0;
int count = 1;

void print(char a, char base, int i){
  // printf("%c, %d: ", a, i);
  if(a-base < i){
    printf("%c", a+26-i);
  }else{
    printf("%c", a-i);
  }
  // cout << endl;
}

void pro(){
  int i, j;
  for(i = len-1, j = 0; i >= 0; i--, j++){
    word[j] = reve[i];
  }
  for(i = 0; i < len; i++){
    if(word[i] >= 'a' && word[i] <= 'z'){
      print(word[i], 'a', count%26);
    }else{
      print(word[i], 'A', count%26);
    }
  }
  len = 0;
}

int main(){
  int i;
  char c;
  while(true){
    if(scanf("%c", &c) == EOF){
      if(len > 0){
	pro();
	cout << endl;
      }
      return 0;
    }
    if((c >='a'&& c <= 'z') || (c >= 'A' && c <= 'Z')){
      reve[len++] = c;
    }else if(c == '\n'){
      pro();
      count = 1;
      cout << endl;
    }else{
      if(len > 0){
	pro();
	count++;
      }
      cout << c;
    }
  }
}
