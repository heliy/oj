#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int array[101];
int find(int n, int t){
  int base = 0, top = n-1, mid = n/2;
  while(base <= top){
    if(array[mid] == t){
      return mid;
    }else{
      if(array[mid] > t){
	top = mid - 1;
      }else{
	base = mid + 1;
      }
      mid = (top + base) / 2;
    }
  }
  return -1;
}

int main(){
  int n, m, i, t, f;
  while(scanf("%d", &n) != EOF){
    for(i = 0; i < n; i++){
      scanf("%d", array+i);
    }
    sort(array, array+n);
    scanf("%d" ,&m);
    for(i = 0; i < m; i++){
      scanf("%d" ,&t);
      f = find(n, t);
      if(f == -1){
	printf("NO\n");
      }else{
	printf("YES\n");
      }
    }
  }
}
