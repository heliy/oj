#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 101
#define MIN(A, B) ((A)<(B)?(A):(B))

using namespace std;

int infos[N][N][2];
double mf[N][N];
int devs[N][N][2];
int ms[N];

int main(){
  int t, m, n, i, ni, mi, best_b, best_p;
  double best_mf;
  cin >> t;
  while(cin >> n){
    for(ni = 0; ni < n; ni++){
      cin >> m;
      ms[ni] = m;
      for(mi = 0; mi < m; mi++){
	cin >> devs[ni][mi][0] >> devs[ni][mi][1];
      }
    }
    for(mi = 0; mi < ms[0]; mi++){
      infos[0][mi][0] = devs[0][mi][0];
      infos[0][mi][1] = devs[0][mi][1];
      mf[0][mi] = (double)infos[0][mi][0]/infos[0][mi][1];
      cout << mf[0][mi] << ' ';
    }
    cout << endl;
    for(ni = 1; ni < n; ni++){
      int mae = ms[ni-1];
      for(mi = 0; mi < ms[ni]; mi++){
	best_mf = 0;
	best_b = 0;
	best_p = 0;
	for(i = 0; i < mae; i++){
	  int b = MIN(infos[ni-1][i][0], devs[ni][mi][0]);
	  int p = infos[ni-1][i][1]+devs[ni][mi][1];
	  double m = (double)b/p;
	  cout << b << ',' << p << ',' << m << " ";
	  if(m > best_mf){
	    best_mf = m;
	    best_b = b;
	    best_p = p;
	  }
	}
	cout << endl;
	mf[ni][mi] = best_mf;
	infos[ni][mi][0] = best_b;
	infos[ni][mi][1] = best_p;
	cout << best_mf << "(" << best_b << "," << best_p << ") \n";
      }
      cout << endl;
    }
    for(best_mf = 0, mi = 0; mi < ms[ni-1]; mi++){
      if(mf[ni-1][mi] > best_mf){
	best_mf = mf[ni-1][mi];
      }
    }
    printf("%.3f\n", best_mf);
  }
}
