#include<stdio.h>

using namespace std;

int main(){
  int n, i;
  int c, sum = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &c);
    sum += c;
  }
  printf("%.2f\n", (double)sum/n);
}
