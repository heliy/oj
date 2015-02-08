#include<stdio.h>

using namespace std;

int matrix[110][110];

int main(){
  int n, i, j, scope, circle;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  for(i = 0; i <= (n+1); i++){
    matrix[i][0] = 99;
    matrix[n+1][i] = 99;
  }
  scope = circle = 0;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      if(matrix[i][j] <= 50){
	scope++;
	if((matrix[i-1][j] > 50) || (matrix[i+1][j] > 50)
	  || (matrix[i][j-1] > 50) || (matrix[i][j+1] > 50)){
	  circle++;
	}
      }
    }
  }
  printf("%d %d\n", scope, circle);
}
