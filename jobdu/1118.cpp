#include<stdio.h>
#include<math.h>

using namespace std;

char numbers[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                    '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int getnum(char c){
  if(c >= '0' && c <= '9'){
    return c - '0';
  }else if(c >= 'A' && c <= 'F'){
    return 10 + (c - 'A');
  }else{
    return 10 + (c - 'a');
  }
}

char format[100];

long from(int m){
  int i, max;
  for(i = 0; format[i] != '\0'; i++);
  long re = 0;
  for(i--, max = i; i >= 0; i--){
    re += getnum(format[i]) * pow(m, max - i);
  }
  return re;
}

void to(long n, int m){
  int i = 0;
  do{
    format[i++] = numbers[n%m];
    n /= m;
  }while(n > 0);
  for(i--; i >= 0; i--){
    printf("%c", format[i]);
  }
  printf("\n");
}

int main(){
  int a, b;
  while(scanf("%d %s %d", &a, format,  &b) != EOF){
    to(from(a), b);
  }
}
