#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
  int n;
  int a[201];
  char line[202], take[202];
  while(scanf("%d", &n) != EOF && n != 0){
    int i, k, j, d;
    for(i = 0; i < n; i++){
      scanf("%d", a+i);
    }
    while(scanf("%d", &k) != EOF && k != 0){
      fgets(line, n, stdin);
      for(j = 0; line[j] != '\0' && line[j] != '\n'; j++)
	;
      for(;j <= n; j++){
	line[j] = ' ';
      }

      for(d = 0; d < k; d++){
	for(j = 1; j <= n; j++){
	  take[a[j-1]] = line[j];
	}
	for(j = 1; j <= n; j++){
	  line[j] = take[j];
	}
      }
      for(j = 1; j < n; j++){
	printf("%c", line[j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
