#include<stdio.h>

using namespace std;

int main(){
  int u[4] = {0, 5, 3, 1};
  int a, b, c, d, e, f;
  while(true){
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if((a+b+c+d+e+f) == 0){
      break;
    }
    int n = f + e + d + (c+3)/4;
    int y = 5 * d + u[c%4];
    if(b > y){
      n += (b - y + 8)/9;
    }
    int x = 36 * (n-f) - 25 * e - 16*d - 9*c - 4*b;
    if(a > x){
      n += (a - x + 35)/36;
    }
    printf("%d\n",n);
  }
  return 1;
}
