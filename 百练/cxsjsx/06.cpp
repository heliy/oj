#include<iostream>

using namespace std;

int cubes[101];

int main(){
  int a, b, c, d, m, i;
  cin >> m;
  for(i = 0; i < 101; i++){
    cubes[i] = i*i*i;
  }
  for(a = 2; a <= m; a++){
    for(b = 2; b < a; b++){
      for(c = b; c < a; c++){
	if(cubes[a] < cubes[b] + cubes[c]){
	  break;
	}
	for(d = c; d < a; d++){
	  if(cubes[a] == cubes[b]+cubes[c]+cubes[d]){
	    cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
	  }else if(cubes[a] < cubes[b]+cubes[c]+cubes[d]){
	    break;
	  }
	}
      }
    }
  }
}
