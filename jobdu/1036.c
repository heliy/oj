#include<stdio.h>
 
int main()
{
    int n,a,b,c;
    while((scanf("%d %d %d %d",&n,&a,&b,&c))!=EOF){
        int i,j;
    int isfind=0;
    int base=a*1000+b*100+c*10;
    for(i=9;i>0;i--){
        if(isfind)
            break;
                for(j=9;j>=0;j--){
            int number=base+j+i*10000;
                        if(number%n==0){
                printf("%d %d %d\n",i,j,number/n);
                isfind=1;
                break;
                }
            }
        }
        if(!isfind)
            printf("0\n");
    }
    return 0;
}
