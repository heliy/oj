#include<iostream>
#include<cstring>
#define N 25

using namespace std;

char str1[N], str2[N];

int main(){
  int n, ni, i, j;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
	LCS[i][j] = 0;
      }
    }
    int totalmax = 0;
    for(i = 0; i < len1; i++){
      int thismax = 0;
      for(j = 0; j < len2; j++){
	if(str1[i+thismax] == str2[j]){
	  thismax++;		
	  	  // cout << i << ", " << j << ", " << thismax << endl;
	}else{
	  if(thismax > totalmax){
	    totalmax = thismax;
	  }
	  thismax = 0;
	}
      }
      if(thismax > totalmax){
	totalmax = thismax;
      }
      thismax = 0;
    }
    cout << totalmax << endl;
  }
}
