#include<iostream>

using namespace std;

int seq[1010];
int mcs[1010][1010];

void print(int mc[1010][1010], int n){
  int i, j;
  for(i = 0; i <= n; i++){
    for(j = 0; j <= n; j++){
      cout << mc[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  int i, j, n;
  while(cin >> n){
    for(i = 1; i <= n; i++){
      cin >> seq[i];
    }
    for(i = 0; i <= n; i++){
      for(j = 0; j <= n; j++){
	mcs[i][j] = 0;
      }
    }
    seq[0] = 0;
    int maxsum = 0, maxj;
    for(i = 1; i <= n; i++){   // 到i的mcs
      for(j = 0; j < i; j++){  // 实际以j为最后的元素的mcs
	if(seq[i] > seq[j]){
	  if(mcs[i][i] < mcs[j][j] + seq[i]){
	    mcs[i][i] = mcs[j][j] + seq[i];
	  }
	}else if(seq[i] > mcs[j][j]){
	  mcs[i][j] = seq[i];
	}else{
	  mcs[i][j] = mcs[j][j];
	}
      }
    }
    maxsum = 0;
    for(j = 1; j <= n; j++){
      if(mcs[n][j] > maxsum){
    	maxsum = mcs[n][j];
      }
    }
    cout << maxsum << endl;
  }
}
