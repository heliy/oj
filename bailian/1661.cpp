#include<iostream>
#include<algorithm>

using namespace std;

struct plant{
  int x1;
  int x2;
  int h;
};

bool cmp(struct plant p1, struct plant p2){
  return p2.h < p1.h ? true : false;
}

struct plant plants[1001];


int n, m;

int inplant(int x, int y){
  int i;
  for(i = 0; i < n; i++){
    if(plants[i].h == y){
      if(x >= plants[i].x1 && x <= plants[i].x2){
	return i;
      }
    }
  }
  return -1;
}

int run(int x, int y, int mode){
  if(y == 0){
    return 0;
  }
  int p = inplant(x, y);
  if(p >= 0){
    int l = -1, r = -1;
    int rl = x - plants[p].x1;
    int rr = plants[p].x2 - x;
    if(mode == 0){
      l = run(x-rl, y, -1) + rl;
      r = run(x+rr, y, 1) + rr;
    }else if(mode == 1){
      l = run(x+rr, y, 1) + rr;
    }else{
      l = run(x-rl, y, -1) + rl;      
    }
    // cout << x << ", " << y << ", " << inplant(x, y) << ", " << r << ", "<< l << endl;
    if(l < 0 && r < 0){
    cout << x << ", " << y << "die\n";
      return -1;
    }
    if(l > r){
      cout << x << ", " << y << "r\n";
    }else{
      cout << x << ", " << y << "l\n";
    }
    return ((l > r)? r: l)+1;
  }else{
    int i;
    for(i = 1; i <= m; i++){
      if(inplant(x, y-i)){
    cout << x << ", " << y << "down\n";
	return run(x, y-i, 0);
      }
    }
    if(y <= m){
      return 0;
    }
    return -1;
  }
}

int main(){
  int t, x, y, ti, ni;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n >> x >> y >> m;
    for(ni = 0; ni < n; ni++){
      cin >> plants[ni].x1 >> plants[ni].x2 >> plants[ni].h;
    }
    sort(plants, plants+n, cmp);
    cout << run(x, y, 0)+y << endl;
  }
}
