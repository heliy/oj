#include<stdio.h>
#include<stdlib.h>
#define N(x,y) (1+(x))*(x)/2+(y)

using namespace std;

int dots[5001][2];
int m[5000*2500];

int onone(int l1, int l2, int l3){
  int a = abs(dots[l1][0] - dots[l2][0]);
  int b = abs(dots[l1][1] - dots[l2][1]);
  int c = abs(dots[l1][0] - dots[l3][0]);
  int d = abs(dots[l1][1] - dots[l3][1]);
  if(a*d == c*b){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int R, C, N;
  scanf("%d %d %d", &R, &C, &N);
  int i, j, k, loci, locj;
  for(i = 0; i < N; i++){
    scanf("%d %d", &loci, &locj);
    dots[i][0] = loci;
    dots[i][1] = locj;
  }
  j = i*i/2;
  for(i = 0; i < j; i++){
    m[i] = 1;
  }
  int max = 2;
  for(i = 0; i < N; i++){
    for(j = i+1; j < N; j++){
      if(m[N(i,j)] == 0){
	continue;
      }
      int count = 2;
      for(k = j+1; k < N; k++){
	if(onone(i, j, k)){
	  m[N(i,k)] = 0;
	  m[N(j,k)] = 0;
	  count++;
	}
      }
      if(count > max){
	max = count;
      }
    }
  }
  printf("%d\n", max);
}
