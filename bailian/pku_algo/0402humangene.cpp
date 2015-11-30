#include<iostream>
#include<cstdio>
#include<cmath>
#define N 102

using namespace std;

int H[N][N];
int patsu[5][5] = {
  {5, -1, -2, -1, -3},
  {-1, 5, -3, -2, -4},
  {-2, -3, 5, -2, -2},
  {-1, -2, -2, 5, -1},
  {-3, -4, -2, -1, 0},
};

char line1[N], line2[N];
int index1[N], index2[N];

void print(int l1, int l2){
  int i, j;
  cout << "H: \n0 - ";
  for(i = 0; i < l1; i++){
    cout << line1[i] << " ";
  }
  cout << "\n- ";
  for(i = 0; i <= l2; i++){
    if(i > 0){
      cout << line2[i-1] << " ";
    }
    for(j = 0; j <= l1; j++){
      cout << H[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void char2index(char *line, int* index, int l){
  int i;
  for(i = 0; i < l; i++){
    if(line[i] == 'A'){
       index[i+1] = 0;
     }
    if(line[i] == 'C'){
      index[i+1] = 1;
    }
    if(line[i] == 'G'){
      index[i+1] = 2;
    }
    if(line[i] == 'T'){
      index[i+1] = 3;
    }
  }
}

int sw(int l1, int l2){
  int i, j, k, m, w;
  H[0][0] = 0;
  for(i = 1; i <= l1; i++){
    H[0][i] = H[0][i-1]+patsu[index1[i-1]][4];
  }
  for(i = 1; i <= l2; i++){
    H[i][0] = H[i-1][0]+patsu[index2[i-1]][4];
  }
  for(i = 1; i <= l2; i++){
    // print(l1, l2);
    for(j = 1; j <= l1; j++){
      // m = 0;
      m = H[i-1][j-1]+patsu[index2[i]][index1[j]];
      w = 0;
      for(k = 1; k <= i; k++){
	w += patsu[index2[i-k+1]][4];
	m = max(m, H[i-k][j]+w);
      }
      w = 0;
      for(k = 1; k <= j; k++){
	w += patsu[index1[j-k+1]][4];
	m = max(m, H[i][j-k]+w);
      }
      H[i][j] = m;
    }
  }
  // print(l1, l2);
  return H[l2][l1];
}

int main(){
  int n, i, l1, l2;
  cin >> n;
  // cin >> line1;
  for(i = 0; i < n; i++){
    cin >> l1 >> line1;
    cin >> l2 >> line2;
    char2index(line1, index1, l1);
    char2index(line2, index2, l2);
    cout << sw(l1, l2) << "\n";
  }
}
