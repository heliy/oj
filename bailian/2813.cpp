#include<stdio.h>
#include<math.h>
#define TRUN(A) ((A)?0:1)

using namespace std;

int wall[17][17];
int dots[17][17];
int assu[17][17];

void print(int array[17][17], int n){
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

int turn(int i, int j){
  assu[i][j] = TRUN(assu[i][j]);
  assu[i+1][j] = TRUN(assu[i+1][j]);
  assu[i][j+1] = TRUN(assu[i][j+1]);
  assu[i][j-1] = TRUN(assu[i][j-1]);
  assu[i-1][j] = TRUN(assu[i-1][j]);
}

int steps(int result, int n){
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      dots[i][j] = 0;
      assu[i][j] = wall[i][j];
    }
  }
  for(j = 1; j <= n; j++){
    dots[1][j] = result%2;
    result /= 2;
  }
  for(i = 1; i < n; i++){
    for(j = 1; j <= n; j++){
      if(dots[i][j]){
	turn(i, j);
      }
    }
    for(j = 1; j <= n; j++){
      dots[i+1][j] = assu[i][j];
    }
  }
  for(j = 1; j <= n; j++){
    if(dots[n][j]){
      turn(n, j);
    }
  }
  int flag = 1;
  for(i = n-1; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(assu[i][j]){
	flag = -1;
      }
    }
  }
  if(flag > 0){
    int count = 0;
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
	count += dots[i][j];
      }
    }
    return count;
  }else{
    return n*n+1;
  }
}

int main(){
  int t, ti;
  scanf("%d", &t);
  for(ti = 0; ti < t; ti++){
    int n, i, j;
    char c;
    scanf("%d", &n);
    for(i = 1; i<= n; i++){
      for(j = 1; j <= n; j++){
	c = ' ';
	while(c != 'y' && c != 'w'){
	  scanf("%c", &c);
	}
	if(c == 'y'){
	  wall[i][j] = 0;
	}else{
	  wall[i][j] = 1;
	}
      }
    }
    j = pow(2, n);
    int min = n*n+1;
    for(i = 0; i < j; i++){
      int t = steps(i, n);
      min = (t < min)?t:min;
    }
    if(min == (n*n+1)){
      printf("inf\n");
    }else{
      printf("%d\n", min);
    }
  }
}
