#include<stdio.h>
#define MAX(A, B) ((A)>(B))?(A):(B)

using namespace std;

long todec(long a, int n){
  long r = 0;
  int i = 1;
  do{
    r += (a%10)*i;
    a /= 10;
    i *= n;
  }while(a > 0);
  return r;
}

int maxs(long a){
  int i = 0;
  do{
    if(a%10 > i){
      i = a%10;
    }
    a /= 10;
  }while(a > 0);
  return i;
}

int begin(long a, long b, long c){
  return MAX(MAX(maxs(a), maxs(b)), maxs(c)) + 1;  
}

int main(){
  int t, i, n;
  long p, q, r;
  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%ld %ld %ld", &p, &q, &r);
    for(n = begin(p, q, r); n <= 16; n++){
      if(todec(p, n)*todec(q, n) == todec(r, n)){
  	break;
      }
    }
    if(n <= 16){
      printf("%d\n", n);
    }else{
      printf("0\n");
    }
  }
  return 0;
}
