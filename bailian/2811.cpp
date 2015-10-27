#include<stdio.h>
#define TRUN(A) ((A)?0:1)

using namespace std;

int lights[7][8];
int button[7][8];
int assume[7][8];

void print(int button[7][8]){
  int i, j;
  for(j = 1; j <= 5; j++){
    for(i = 1; i <= 6; i++){
      printf("%d", button[j][i]);
      if(i < 6){
	printf(" ");
      }
    }
  printf("\n");
  }
}

void turn(int i, int j){
  assume[j][i] = TRUN(assume[j][i]);
  assume[j-1][i] = TRUN(assume[j-1][i]);
  assume[j][i-1] = TRUN(assume[j][i-1]);
  assume[j][i+1] = TRUN(assume[j][i+1]);
  assume[j+1][i] = TRUN(assume[j+1][i]);
}

int isok(int result){
  int i, j;
  for(j = 1; j <= 5; j++){     // 最初
    for(i = 1; i <= 6; i++){
      assume[j][i] = lights[j][i];
      button[j][i] = 0;
    }
  }
  for(i = 1; i <= 6; i++){     // 第一行方案
    button[1][i] = result%2;
    result /= 2;
  }
  for(j = 1; j < 5; j++){
    for(i = 1; i <= 6; i++){   // 按j行方案操作
      if(button[j][i] == 1){
	turn(i, j);
      }
    }
    for(i = 1; i <= 6; i++){   // 下一行方案
      if(assume[j][i] == 1){
	button[j+1][i] = 1;
      }
    }
  }

  for(i = 1; i <= 6; i++){     // 第五行操作
    if(button[5][i] == 1){
      turn(i, 5);
    }
  }
  for(j = 4; j <= 5; j++){     // 是否全灭
    for(i = 1; i <= 6; i++){
      if(assume[j][i] == 1){
	return 0;
      }
    }
  }
  return 1;
}

int main(){
  int n, ni;
  scanf("%d", &n);
  for(ni = 0; ni < n; ni++){
    int i, j, result;
    for(i = 0; i < 7; i++){
      for(j = 0; j < 8; j++){
	lights[i][j] = button[i][j] = assume[i][j] = 0;
      }
    }
    for(j = 1; j <= 5; j++){
      for(i = 1; i <= 6; i++){
	scanf("%d", &lights[j][i]);
	button[j][i] = 0;
      }
    }
    for(result = 0; result < 64; result++){
      if(isok(result)){
	printf("PUZZLE #%d\n", ni+1);
	print(button);
	break;
      }
    }
  }
}
