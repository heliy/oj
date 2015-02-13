#include<stdio.h>
#define N1 1000
#define N2 10000

using namespace std;

int to[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int count[N1][N2];

int main(){
  char line[100];
  int n, i, j;
  for(i = 0; i < N1; i++){
    for(j = 0; j < N2; j++){
      count[i][j] = 0;
    }
  }
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", line);
    for(j = 0; line[j] != '\0' && line[j] != '\n'; j++)
      ;
    int p = 1, num = 0;
    for(j--; j >= 0; j--){
      if(line[j] == '-'){
	continue;
      }
      if(line[j] >= '0' && line[j] <= '9'){
	num += (line[j] - '0') * p;
      }else{
	num += (to[line[j] - 'A']) * p;
      }
      p *= 10;
    }
    count[num/N2][num%N2]++;
  }
  int is_du = 0;
  for(i = 1; i < N1; i++){
    for(j = 1; j < N2; j++){
      if(count[i][j] > 1){
  	printf("%03d-%04d %d\n", i, j, count[i][j]);
  	is_du = 1;
      }
    }
  }
  if(is_du == 0){
    printf("No duplicates.\n");
  }
  return 0;
}
