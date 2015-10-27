#include<stdio.h>

using namespace std;

int wall[22][22];
int alre[22][22];

int count(int i, int j){
  if(i == 0 || i == 21 || j == 0 || i == 21){
    return 0;
  }
  if(alre[i][j] == 1){
    return 0;
  }
  alre[i][j] = 1;
  if(wall[i][j] == 0){
    return 0;
  }
  return 1+count(i+1, j)+count(i, j+1)+count(i-1, j)+count(i, j-1);
}


int main(){
  int w, h, i, j, initi, initj;
  char c;
  while(scanf("%d %d", &w, &h) != EOF && w && h){
    for(i = 0; i < 22; i++){
      for(j = 0; j < 22; j++){
        wall[i][j] = 0;
	alre[i][j] = 0;
      }
    }
    for(i = 1; i <= h; i++){
      for(j = 1; j <= w; j++){
	c = ' ';
	while(c != '.' && c != '#' && c != '@'){
	  scanf("%c", &c);
	}
	switch(c){
	case '#':
	  break;
	case '@':
	  initi = i;
	  initj = j;
	case '.':
	  wall[i][j] = 1;
	  break;
	default:
	  break;
	}
      }
    }
    printf("%d\n", count(initi, initj));
  }
}
