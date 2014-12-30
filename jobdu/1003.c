#include<stdio.h>

#define MAX_L 30

void get2long(char *);
int mygetline(char*);

long int a,b;

void main()
{
  long int result;
  char str[MAX_L];
  while(mygetline(str)>0){
      get2long(str);
      result=a+b;
      printf("%ld\n",result);
  }
}

int mygetline(char *s)
{
  int c,i;
  for(i=0;(c=getchar())!=EOF&&c!='\n';i++)
    s[i]=c;
  s[i]='\0';
  return i;
}

long int input(char,long int);

void get2long(char *str)
{
  char *p=str;
  a=b=0;
  int a_neg=1,b_neg=1;
  if(*p=='-'){
    a_neg=-1;
    p++;
  }
  while(*p!=' '){
    a=input(*p,a);
    p++;
  }
  p++;
  if(*p=='-'){
    b_neg=-1;
    p++;
  }
  while(*p!='\0'){
    b=input(*p,b);
    p++;
  }
  a*=a_neg;
  b*=b_neg;
}

long int input(char c,long int num)
{
  if(c==',')
    return num;
  else{
    return ((num)*10+(c-'0')); 
  }
}
