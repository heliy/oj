#include<iostream>
#include<cstdio>

using namespace std;

int board[77][77];
int cango[77][77];
int iused[77][77];

int w, h;

bool iswin(int i, int j){
  if(i == 0 || j == 0 || i == h+1 || j == w+1){
    return true;
  }else{
    return false;
  }
}

void take(int y, int x, int step, int mae){
  int i, j;
  if(step == 0){
    for(i = 0; i <= h+1; i++){
      for(j = 0; j <= w+1; j++){
	cango[i][j] = 0;
	iused[i][j] = 0;
      }
    }    
  }
  if(x < 0 || y < 0 || x > h+1 || y > w+1){
    return;
  }
  if(iused[x][y]){
    if(step >= cango[x][y]){
      return;
    }
  }
  cango[x][y] = step;
  iused[x][y] = 1;
  if((step > 0) && board[x][y]){
    return;
  }
  if(mae == 1){
    take(y, x-1, step, 1);
  }else{
    take(y, x-1, step+1, 1);    
  }
  if(mae == 2){
    take(y+1, x, step, 2);
  }else{
    take(y+1, x, step+1, 2);    
  }
  if(mae == 3){
    take(y, x+1, step, 3);
  }else{
    take(y, x+1, step+1, 3);    
  }
  if(mae == 4){
    take(y-1, x, step, 4);
  }else{
    take(y-1, x, step+1, 4);    
  }
  if(mae == 0){
    take(y, x-1, step+1, 1);    
    take(y+1, x, step+1, 2);    
    take(y, x+1, step+1, 3);    
    take(y-1, x, step+1, 4);    
  }
}

int main(){
  int i, j, x1, y1, x2, y2;
  int n = 0, k;
  char c;
  while((cin >> w >> h) && w){
    n++;
    for(i = 0; i < 77; i++){
      for(j = 0; j < 77; j++){
	board[i][j] = 0;
      }
    }
    for(i = 1; i <= h; i++){
      for(j = 1; j <= w; j++){
	c = 'v';
	while(c != 'X' && c != ' '){
	  scanf("%c", &c);
	}
	if(c == 'X'){
	  board[i][j] = 1;
	}
      }
    }
    k = 0;
    cout << "Board #" << n << ":" << endl;
    while (cin >> x1 >> y1 >> x2 >> y2 && x1){
      k++;
      cout << "Pair " << k << ": ";
      take(x1, y1, 0, 0);
      if(cango[y2][x2]){
	cout << cango[y2][x2] << " segments." << endl;
      }else{
	cout << "impossible." << endl;
      }
    }
    cout << endl;
  }
}
