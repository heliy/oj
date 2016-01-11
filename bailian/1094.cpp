#include<iostream>
#include<cstdio>

using namespace std;

int map[27][27];
int order[27];
bool isordered[27];

int main(){
  int n, m, i, j, k;
  char a, b;
  while(cin >> n >> m){
    if(n == 0 && m == 0){
      break;
    }
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	map[i][j] = 0;
      }
    }
    for(k = 0; k < m; k++){
        scanf("%c<%c", &a, &b);
        i = a - 'A';
	j = b - 'B';
	map[i][j] = 1;
    }
    
  }
}

