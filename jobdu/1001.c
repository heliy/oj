#include<stdio.h>
#include<stdlib.h>
#define MAX_D 1000

void main()
{
  int flag,row,col,tmp,i,j,result;
  int M[MAX_D][MAX_D],iszero[MAX_D*2];
  while(scanf("%d",&flag)!=EOF&&flag!=0){
    result=0;
    row=flag;
    scanf("%d",&col);
    for(i=0;i<row;i++)
      for(j=0;j<col;j++){
	scanf("%d",&M[i][j]);
	iszero[i]=0;
	iszero[row+j]=0;
      }
    for(i=0;i<row;i++)
      for(j=0;j<col;j++){
	scanf("%d",&tmp);
	M[i][j]+=tmp;
	if(M[i][j]!=0){
	  iszero[i]=1;
	  iszero[row+j]=1;
	}
    }
    for(i=0;i<row+col;i++){
      if(iszero[i]==0)
	result++;
    }
    printf("%d\n",result);
  }
}
