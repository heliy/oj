#include<stdio.h>
 
int main()
{
    int x,y,max_x,max_y,min_x,min_y,count;
    count=0;
    max_x=max_y=-231;
    min_x=min_y=231;
    while((scanf("%d %d",&x,&y))!=EOF){
                if(x==0&&y==0){
                        if(count==0)
                break;
                else{
                                printf("%d %d %d %d\n",min_x,min_y,max_x,max_y);
                count=0;
                max_x=max_y=-231;
                min_x=min_y=231;
            }
            }else{
                        if(x<min_x)
                min_x=x;
            if(x>max_x)
                max_x=x;
            if(y<min_y)
                min_y=y;
            if(y>max_y)
                max_y=y;
            count++;
        }
    }
    return 0;
}
