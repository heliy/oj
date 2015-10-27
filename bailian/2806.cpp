#include<iostream>
#include<cstring>
#define MAX(A, B) ((A)>(B)?(A):(B))

using namespace std;

int LCS[202][202];

char a[202], b[202];
int main(){
  a[0] = b[0] = ' ';
  while(cin >> &a[1] >> &b[1]){
    int al = strlen(a);
    int bl = strlen(b);
    int i, j;
    for(i = 0; i <= al; i++){
      for(j = 0; j <= bl; j++){
	LCS[i][j] = 0;
      }
    }
    for(i = 1; i < al; i++){
      for(j = 1; j < bl; j++){
	if(LCS[i][j]){
	  continue;
	}
	if(a[i] == b[j]){
	  LCS[i][j] = LCS[i-1][j-1]+1;
	}else{
	  LCS[i][j] = MAX(LCS[i-1][j], LCS[i][j-1]);
	}
      }
    }
    cout << LCS[al-1][bl-1] << endl;
  }
}
