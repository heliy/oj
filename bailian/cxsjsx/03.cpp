#include<iostream>
#include<cstdio>
#include<vector>
#define N 110

using namespace std;

int mis[N];
int bres[N][N];
int pris[N][N];

int select(int s, int least){
  int min = -1, minP = 100000, i;
  for(i = 0; i < mis[s]; i++){
    if(bres[s][i] >= least && pris[s][i] < minP){
      minP = pris[s][i];
      min = i;
    }
  }
  return min;
}

int main(){
  int t, ti, n, m, mi, i, curB, curP;
  double maxBp, bp;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n;
    for(i = 0; i < n; i++){
      cin >> mis[i];
      for(mi = 0; mi < mis[i]; mi++){
	cin >> bres[i][mi] >> pris[i][mi];
      }
    }
    maxBp = 0;
    for(i = 0; i < n; i++){
      for(mi = 0; mi < mis[i]; mi++){
	curB = bres[i][mi];
	curP = pris[i][mi];
	int s = -1;
	for(m = 0; m < n; m++){
	  if(m == i){
	    continue;
	  }
	  s = select(m, curB);
	  if(s < 0){
	    break;
	  }
	  curP += pris[m][s];
	}
	if(s < 0 && n > 1){
	  continue;
	}
	bp = (float)curB/curP;
	if(bp > maxBp){
	  maxBp = bp;
	}
      }
    }
    // if((int)(1000*maxBp)%10 >= 5){
    //   maxBp += 0.001;
    // }
    printf("%.3f\n", maxBp);
  }
}
