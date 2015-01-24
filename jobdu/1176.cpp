#include<stdio.h>
#include<math.h>

#define MIN(A,B) (A)>(B)?(B):(A)

using namespace std;

int numbers[1002];

int main(){
  int i, n, d;
  while(scanf("%d", &n) != EOF){
    for(i = 1; i <= n; i++){
      scanf("%d", numbers+i);
    }
    scanf("%d", &d);
    int start = pow(2, d-1);
    if(start <= n){
      int limit = MIN(start*2-1, n);
      for(i = start; i < limit; i++){
	printf("%d ", numbers[i]);
      }
      printf("%d\n", numbers[i]);
    }else{
      printf("EMPTY\n");
    }
  }
  return 0;
}
