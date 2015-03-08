#include<iostream>

using namespace std;

struct device{
  int b;
  int p;
  int n;
  int mi;
};

bool cmp(struct device d1, struct device d2){
  return d1.b < d2.b;
}

struct device devices[110];

int cases[110][210][2];
int mins[110];
int ms[110];

int main(){
  int t, ti, n, ni, m, mi, i, total;
  cin >> t;
  for(ti = 0; ti < t; t++){
    cin >> n;
    total = 0;
    for(ni = 0; ni < n; ni++){
      int minprice = 9999999;
      cin >> m;
      for(mi = 0; mi < m; mi++){
	cin >> cases[ni][mi][0] >> cases[ni][mi][1];
	devices[total].b = cases[ni][mi][0];
	devices[total].p = cases[ni][mi][1];
	devices[total].mi = mi;
	devices[total++].n = ni;
	if(cases[ni][mi][1] < minprice){
	  minprice = cases[ni][mi][1];
	}
      }
      mins[ni] = minprice;
      ms[ni] = m;
    }
    sort(devices, devices+total);
    double bp = 0;
    for(i = 0; i < total; i++){
      int otherp = 0;
      for(ni = 0; ni < n; ni++){
	if(ni == devices[i].n){
	  continue;
	}
	otherp += mins[ni];
      }
      doule thisbp = (double)devices[i].b/(otherp+devices[i].p);
      if(thisbp > bp){
	bp = thisbp;
      }
      cases[devices[i].n][ms[devices[i].mi]][0] = 999999;

    }

  }
}
