#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

double nextvalue(){
  char buf[10];
  cin >> buf;
  switch(buf[0]){
  case '*':
    return nextvalue()*nextvalue();
  case '/':
    return nextvalue()/nextvalue();
  case '+':
    return nextvalue()+nextvalue();
  case '-':
    return nextvalue()-nextvalue();
  default:
    return atof(buf);
  }
}

int main(){
  printf("%f\n", nextvalue());
}
