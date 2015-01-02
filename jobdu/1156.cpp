#include<stdio.h>
#include<stdlib.h>

#define N 201

using namespace std;

int main(){
  int books[N];
  int persons[N];
  int n,m,i;
  while(scanf("%d %d", &n, &m) != EOF){
    for(i = 0; i < N; i++){
      books[i] = 0;
    }
    for(i = 0; i < n; i++){
      scanf("%d", &persons[i]);
      books[persons[i]]++;
    }
    for(i = 0; i < n; i++){
      if(books[persons[i]] == 1){
	printf("BeiJu\n");
      }else{
	printf("%d\n", books[persons[i]] - 1);
      }
    }
  }
  return 0;
}
