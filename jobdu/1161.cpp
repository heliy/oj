#include<stdio.h>
#include<stdlib.h>

using namespace std;

char format[3000][3000];
char temp[6][6];

void paint(int begin_i, int begin_j, int n, int level){
  int i,j;
  if(level == 1){
    for(i = 0; i < n; i++){
      format[begin+i][begin+j] = temp[i][j];
    }
  }else{
    int step = n*(level-1);
    paint(begin_i, begin_j, n, level-1);
    paint(begin_i+step*2, begin_j, n, level-1);
    paint(begin_i+step, begin_j+step, n, level-1);
    paint(begin_i, begin_j+ste*2, n, level-1);
    paint(begin_i+step*2, begin_j+step*2, n, level-1);
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
	temp[i][j] = c;
      }
    }
    scanf("%d", &q);
    paint(0, 0, n, q);
    size = n*(q)
  }
}
