#include<iostream>

using namespace std;

int rev(int d){
  if(d < 3){
    return d + 3;
  }else{
    return d -3;
  }
}

int main(){
  int m, mi, n, i, step;
  char line[10];
  cin >> m;
  for(mi = 0; mi < m; mi++){
    cin >> n;
    int x, y , z, p, l, u, t;
    x = y = z = p = 0;
    l = 4;
    u = 2;
    while(n-- > 0){
      cin >> line >> step;
      switch(line[0]){
      case 'f':
	break;
      case 'b':
	p = rev(p);
	l = rev(l);
	break;
      case 'l':
	t = l;
	l = rev(p);
	p = t;
	break;
      case 'r':
	t = p;
	p = rev(l);
	l = t;
	break;
      case 'u':
	t = u;
	u = rev(p);
	p = t;
	break;
      case 'd':
	t = p;
	p = rev(u);
	u = t;
	break;
      }
      switch(p){
      case 0:
	x += step;
	break;
      case 1:
	y += step;
	break;
      case 2:
	z += step;
	break;
      case 3:
	x -= step;
	break;
      case 4:
	y -= step;
	break;
      case 5:
	z -= step;
	break;
      }
    }
    cout << x << ' ' << y << ' ' << z << ' ' << p << endl;
  }
}
