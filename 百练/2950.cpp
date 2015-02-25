#include<iostream>
#include<stdlib.h>

using namespace std;

int a[100][100];
int m, n, limit;
int loc_i, loc_j;

int take(bool is_init){
  int i, j, max, max_i, max_j;
  max = 0;
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      if(a[i][j] > max){
	max_i = i;
	max_j = j;
	max = a[i][j];
      }
    }
  }
  if(max == 0){
    return 0;
  }
  int taketime;
  if(is_init){
    taketime = max_i + 2;
  }else{
    taketime = abs(loc_i - max_i) + abs(loc_j - max_j) + 1;
  }
  //  cout << taketime << ", " << max_i+1 << ", " << limit << '\n';
  if(taketime + max_i + 1 <= limit){
    limit -= taketime;
    loc_i = max_i;
    loc_j = max_j;
    a[loc_i][loc_j] = 0;
    return max;
  }else{
    return 0;
  }
}

int main(){
  int t, ti;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    int i, j, get = 0;
    cin >> m >> n >> limit;
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        cin >> a[i][j];
      }
    }

    int g;
    get = take(true);
    if(get != 0){
      while((g = take(false)) > 0){
        get += g;
      }
    }
    cout << get << '\n';
  }
  return 0;
}
