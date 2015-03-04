#include<stdio.h>
#include<math.h>

using namespace std;

/* 找不到错误 T T */

int init[9];
int steps[9][6] = {
  {1,2,4,5}, {1,2,3}, {2,3,5,6}, {1,4,7},
  {2,4,5,6,8}, {3,6,9}, {4,5,7,8}, {7,8,9}, {5,6,8,9},
};
int mode[9];
int status[9];
int min[9];

void print(int a[9]){
  int i;
  for(i = 0; i < 9; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

int isok(int r, int level){
  int i, j, k = 1, c = 0;
  for(i = 0; i < 9; i++){
    status[i] = init[i];
    mode[i] = r%2;
    c += mode[i];
    r /= 2;
  }
  if(c != level){
    return -1;
  }
  for(i = 0; i < 9; i++){
    if(mode[i]){
      for(j = 0; steps[i][j] != '\0'; j++){
	status[steps[i][j]-1] = (status[steps[i][j]-1]+1)%4;
      }
    }
  }
  for(i = 0; i < 9; i++){
    if(status[i]){
      k = 0;
    }
  }
  if(k){
    for(i = 0, j = 0; i < 9; i++){
      j += mode[i];
    }
    return j;
  }else{
    return -1;
  }
}

int main(){
  int i, j, t, k, maxsteps = pow(2, 9);
  for(i = 0; i < 9; i++){
    scanf("%d", &init[i]);
  }
  for(i = 0; i <= 9; i++){
    for(k = 0; k < maxsteps; k++){
      t = isok(k, i);
      if(t > 0){
	for(j = 0, k = 0; j < 9; j++){
	  if(mode[j]){
	    min[k++] = j+1;
	  }
	}
	for(j = 0; j < k; j++){
	  if(j){
	    printf(" ");
	  }
	  printf("%d", min[j]);
	}
	printf("\n");
	return 0;
      }
    }
  }
  return 0;
}
