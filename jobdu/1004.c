#include<stdio.h>

#define MAX_N 999999
#define MAX_VAL 1000000

void printmid(int*,int,int*,int);

void main()
{
  int line_no=0;
  int tmp;
  int a[MAX_N],b[MAX_N],a_num=0,a_i=0,b_num=0,b_i=0;

  while((scanf("%d",&tmp))!=EOF){
    if(line_no==0){                //第一行输入
      if(a_num==0){                //输入值为个数
	a_num=tmp;
      }else{
	a[a_i++]=tmp;
	if(a_i==a_num){            //第一行满，进入第二行
	  line_no=1;
	  a[a_i]=MAX_VAL;
	}
      }
    }else{                         //第二行输入
      if(b_num==0){
	b_num=tmp;                 //第二行个数
      }else{
	b[b_i++]=tmp;
	if(b_i==b_num){            //第二行满，计算中间数，重回第一行
	  b[b_i]=MAX_VAL;
	  printmid(a,a_num,b,b_num);
	  b_num=a_num=b_i=a_i=line_no=0;
	}
      }
    }
  }
}

void printmid(int *a,int a_num,int *b,int b_num)
{
  int mid=(a_num+b_num);
  if(mid%2==0)
    mid/=2;
  else
    mid=(mid+1)/2;

  int i,val,a_i,b_i;
  for(a_i=b_i=i=0;i<mid;i++){
    if(a[a_i]<b[b_i]){
      val=a[a_i++];
    }else{
      val=b[b_i++];
    }
  }
  printf("%d\n",val);
}
