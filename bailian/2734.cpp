#include<stdio.h>

using namespace std;

int main(){
  int n;
  int a[20];
  scanf("%d", &n);
  int i = 0;
  do{
    a[i++] = n%8;
    n /= 8;
  }while(n > 0);
  do{
    printf("%d", a[--i]);
  }while(i > 0);
  printf("\n");
  return 0;
}
