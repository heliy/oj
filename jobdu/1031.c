#include<stdio.h>
 
int xxx(int);
 
int main()
{
    int d;
    while((scanf("%d",&d))!=EOF){
        if(d==0)
            break;
        else
            printf("%d\n",xxx(d));
    }
    return 0;
}
 
int xxx(int d)
{
    if(d==1)
        return 0;
    if(d%2==0)
        return xxx(d/2)+1;
    else
        return xxx((3*d+1)/2)+1;
}
