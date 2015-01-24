#include<stdio.h>
#include<math.h>

#define MIN(A,B) ((A)<(B)?(A):(B))

using namespace std;

long int subs(long int m, long int n){
  long int level = (long int)(log((double)n/m)/log(2));
  long int max = m * pow(2, level);
  return MIN(pow(2, level+1) - 1, pow(2, level) + n - max);
}

int main(){
  long m, n;
  while(scanf("%ld %ld", &m, &n) != EOF){
    if(m == 0 && n == 0){
      break;
    }
    printf("%ld\n", subs(m, n));
  }
  return 0;
}
