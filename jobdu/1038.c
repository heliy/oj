#include<stdio.h>

int main()
{
  long int fac[11];
  int i;
  fac[0]=1;
  for(i=1;i<11;i++){
    fac[i]=fac[i-1]*i;
  }

  long int input;
  int loc,bef;
  while((scanf("%ld",&input))!=EOF){
    for(i=10;i>=0;i--){
      if(input>=fac[i])
	input-=fac[i];
    }
    if(input==0)
      printf("YES\n");
    else
      printf("NO\n");
  }

}
