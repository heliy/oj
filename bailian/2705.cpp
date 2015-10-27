#include<iostream>

using namespace std;

int tour[65];

int main(){
  int n, ni;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    int m, mi, i, j, mae, t;
    cin >> m;
    for(i = 0; i < 65; i++){
      tour[i] = 1;
    }
    mae = i = 0;
    for(mi = 0; mi < m; mi++){
      cin >> t;
      i += (t-mae);
      for(j = 0; j < 3 && i < 60; i++, j++){
	tour[i] = 0;
      }
      mae = t;
    }
    j = 0;
    for(i = 0; i < 60; i++){
      j += tour[i];
    }
    cout << j << endl;
  }
}
