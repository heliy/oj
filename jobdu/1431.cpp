#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main(){
  int array[1000001];
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF){
    int i;
    for(i = 0; i < n; i++){
      scanf("%d", array+i);
    }
    sort(array, array+n);
    for(i = n - 1; i >= n - m; i--){
      printf("%d", array[i]);
      if(i > n - m){
	printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
