#include<stdio.h>
#include<stdlib.h>

using namespace std;

char format[3000][3000];
char temp[6][6];


int pow(int i, int n){
  int x = 1;
  while(n > 0){
    x *= i;
    n--;
  }
  return x;
}

void paint(int begin_i, int begin_j, int n, int level, int valid){
  int i,j;
  int size = pow(n, level);
  if(valid == 0){
    for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
        format[begin_i+i][begin_j+j] = ' ';
      }
    }
    return;
  }
  printf("%d %d,level:%d\n", begin_i, begin_j, level);
  if(level == 1){
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        format[begin_i+i][begin_j+j] = temp[i][j];
	printf("%02d-%02d,%c ",begin_i+i, begin_j+j, temp[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }else{
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	if(temp[i][j] == ' '){
	  paint(begin_i+step*i/n, begin_j+step*j/n, n, 0, 0);
	}
	else{
	  paint(begin_i+step*i/n, begin_j+step*j/n, n, level-1, 1);
	}
      }
    }
  }
}


int main(){
  int n, q;
  while(scanf("%d", &n) != EOF){
    if(n == 0){
      break;
    }
    char c;
    int i, j;
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	scanf("%c", &c);
	if(c == '\n'){
	  j--;
	  continue;
	}
	temp[i][j] = c;
      }
    }
    scanf("%d", &q);
    paint(0, 0, n, q, 1);
    int size = pow(n, q);
    printf("%d\n",size);
    for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
    	printf("%c", format[i][j]);
      }
      printf("\n");
    }
  }
}
