#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dots[1441][1010];
int nums[1441];
int group[1441];
int res[1441];

int main(){
  int t, ti, n, ni, k, ki, h, m;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    for(ni = 0; ni < 1441; ni++){
      nums[ni] = res[ni] = 0;
      group[ni] = ni;
    }
    cin >> n;
    for(ni = 0; ni < n; ni++){
      cin >> k;
      for(ki = 0; ki < k; ki++){
	scanf("%d:%d", &h, &m);
	dots[h*100+m][nums[h*100+m]++] = ni;
      }
    }
    // for(k = 0; k < 5; k++){
    //   for(ni = 0; ni < nums[k]; ni++){
    // 	cout << dots[k][ni] << " ";
    //   }
    //   cout << endl;
    // }
    for(k = 0; k < 1441; k++){
      for(ni = 1; ni < nums[k]; ni++){
	group[dots[k][ni]] = group[dots[k][0]];
      }
    }
    m = 0;
    for(ni = 0; ni < n; ni++){
      if(group[ni] == ni){
	nums[m++] = ni;
      }
    }
    cout << m << endl;
    for(h = 0; h < m; h++){
      k = 0;
      for(ni = 0; ni < n; ni++){
	if(group[ni] == nums[h]){
	  k++;
	}
      }
      res[h] = k;
    }
    sort(res, res+m);
    for(h = 0; h < m; h++){
      if(h){
	cout << " ";
      }
      cout << res[h];
    }
    cout << endl;
  }
}
