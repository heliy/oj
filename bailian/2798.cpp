#include<stdio.h>

using namespace std;

char tohex(char* begin){
  int x = (begin[0] - '0')*8 + (begin[1] - '0')*4 + (begin[2] - '0')*2 
    + (begin[3] - '0');
  if(x > 9){
    return 'A' + x - 10;
  }else{
    return '0' + x;
  }
}

int main(){
  int n, i, j, k;
  char array[10010];
  char hex[3000];
  scanf("%d", &n);
  fgets(array, 10001, stdin);
  for(i = 0; i < n; i++){
    for(j = 0; j < 4; j++){
      array[j] = '0';
    }
    fgets(array+4, 10001, stdin);
    for(j = 4; array[j] == '0' || array[j] == '1'; j++)
      ;
    k = 0;
    while(j > 4){
      hex[k++] = tohex(array+j-4);
      j -= 4;
    }
    k--;
    while(k >= 0){
      printf("%c", hex[k--]);
    }
    printf("\n");
  }
}
