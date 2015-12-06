#include<iostream>
#include<cstdio>
#include<cmath>

#define N 1003

using namespace std;

double min_times[N];
int wis[N];
double sis[N];

int main(){
  int n, b, l, wi, si, i, j;
  while(cin >> b >> l >> n){
    if(b == 0){
      break;
    }
    for(i = 1; i <= n; i++){
      cin >> wi >> si;
      wis[i] = wi;
      sis[i] = ((double)l/si)*60;
    }
    min_times[0] = 0;
    for(i = 1; i <= n; i++){
      double this_time = sis[i];
      int already = wis[i];
      double min_time = min_times[i-1]+this_time;
      for(j = i-1; j > 0; j--){
	if(wis[j]+already > b){
	  break;
	}
	this_time = fmax(this_time, sis[j]);
	already += wis[j];
	min_time = fmin(min_time, min_times[j-1]+this_time);
      }
      // cout << i << ": " << min_time << endl;
      min_times[i] = min_time;
    }
    printf("%.1f\n", min_times[n]);
  }
}
