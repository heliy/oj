#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 10
#define MAX 141000

using namespace std;

/* AC */

int seq[N];
int valids[MAX][N];
bool isin[N];
int valid_num;

int between(int x, int y){
  int x1, x2, y1, y2;
  x1 = (x-1)/3;
  x2 = x-x1*3;
  y1 = (y-1)/3;
  y2 = y-y1*3;
  x1 = abs(x1-y1);
  x2 = abs(x2-y2);
  if((x1*x2 == 2) || (x1*x2 == 0 && x1 != 2 && x2 != 2) || (x1*x2 == 1)){
    return -1;
  }else{
    return (x+y)/2;
  }
}

bool isvalid(int n){
  int i;
  for(i = 0; i < 10; i++){
    isin[i] = false;
  }
  isin[seq[0]] = true;
  for(i = 1; i < n; i++){
    isin[seq[i]] = true;
    int b = between(seq[i-1], seq[i]);
    if(b >= 0){
      if(!isin[b]){
	return false;
      }
    }
  }
  return true;
}

int main(){
  // cout << between(1, 5) << endl;
  int t, ti, n, i, j;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n;
    for(i = 0; i < n; i++){
      cin >> seq[i];
    }
    sort(seq, seq+n);
    valid_num = 0;
    do{
      if(isvalid(n)){
	for(i = 0; i < n; i++){
	  valids[valid_num][i] = seq[i];
	}
	valid_num++;
      }
    }while(next_permutation(seq, seq+n));
    cout << valid_num << endl;
    for(i = 0; i < valid_num; i++){
      printf("%d", valids[i][0]);
      for(j = 1; j < n; j++){
    	printf(" %d", valids[i][j]);
      }
      printf("\n");
    }
  }
}
