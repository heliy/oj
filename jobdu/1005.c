#include<stdio.h>


void main()
{
  int applications[40000][7],schools[100][6],ranklist[40000];
  int N,M,K;
  while(scanf("%d",&N)!=EOF){
    scanf("%d %d",&M,&K);
    int i,j;
    for(i=0;i<M;i++)
      scanf("%d",&schools[i][1]);
    for(i=0;i<N;i++){
      for(j=0;j<K+2;j++){
	scanf("%d",&applications[i][j+1]);
      }
      applications[i][0]=-1;
    }
  }
}
