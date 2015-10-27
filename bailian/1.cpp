#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char keyword[20], cipher[100], grid[20][20], message[20][20];
char co[20];

void print(char a[20][20], int row, int col){
  int i, j;
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      cout << a[i][j];
    }
    // cout << endl;
  }
  cout << endl;
}

int find(char*a, char c){
  int i;
  for(i = 0; a[i] != '\0' && a[i] != c; i++)
    ;
  return i;
}
int main(){
  while(cin >> keyword){
    if(strcmp(keyword, "THEEND") == 0){
      break;
    }
    cin >> cipher;
    int total = strlen(cipher);
    int col = strlen(keyword);
    int row = total/col;
    int i, j;
    // cout << row << ", " << col << endl;
    for(i = 0; i < total; i++){
      grid[i%row][i/row] = cipher[i];
    }
    for(i = 0; i < col; i++){
      co[i] = keyword[i];
    }
    sort(co, co+col);
    // print(grid, row, col);
    for(i = 0; i < col; i++){
      int index = find(keyword, co[i]);
      keyword[index] = 'a';
      for(j = 0; j < row; j++){
	message[j][index] = grid[j][i];
      }
    }
    print(message, row, col);
  }
  return 0;
}
