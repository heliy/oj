#include<stdio.h>
#include<math.h>

using namespace std;

int format[100];
void dec2m(long long n, int m){
  int i;
  for(i = 0; n > 0; i++){
    format[i] = n%m;
    n /= m;
  }
  if(i == 0){
    printf("0");
  }
  for(i--;i >= 0; i--){
    printf("%d", format[i]);
  }
  printf("\n");
}

int main(){
  int m;
  long long A, B;
  while(scanf("%d", &m) != EOF){
    if(m == 0){
      break;
    }
    scanf("%lld %lld", &A, &B);
    dec2m(A+B, m);
  }
  return 0;
}
