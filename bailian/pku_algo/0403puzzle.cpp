#include<iostream>
#include<cmath>

#define N 101
#define MAX 999999999
#define MIN(a, b) ((a)<(b)?(a):(b))

using namespace std;

long long f[N][N];
int nums[N];

int main(){
  int n, i, j, k, scale;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> nums[i];
  }
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      f[i][j] = 0;
    }
  }
  for(scale = 2; scale < n; scale++){
    for(i = 0; i+scale < n; i++){
      j = i + scale;
      if(scale == 2){
	f[i][j] = nums[i]*nums[i+1]*nums[j];
      }else{
	long long minf = MAX;
	for(k = i+1; k < j; k++){
	  minf = MIN(minf, f[i][k]+f[k][j]+nums[i]*nums[k]*nums[j]);
	}
	f[i][j] = minf;
      }
    }
  }
  cout << f[0][n-1] << endl;
}
