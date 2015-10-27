#include<iostream>
#define N 21
using namespace std;

int W[N][N][N];

long long w(int a, int b, int c){
  if(a <= 0 || b <= 0 || c <= 0){
    return 1;
  }else if(a > 20 || b > 20 || c > 20){
    return w(20,20,20);
  }else if(a < b && b < c){
    return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  }else{
    return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
  }
}

int main(){
  int a, b, c;
  for(a = 0; a < N; a++){
    for(b = 0; b < N; b++){
      for(c = 0; c < N; c++){
	if(a*b*c == 0){
	  W[a][b][c] = 1;
	}else if(a < b && b < c){
	  W[a][b][c] = W[a][b][c-1]+W[a][b-1][c-1]-W[a][b-1][c];
	}else{
	  W[a][b][c] = W[a-1][b][c]+W[a-1][b-1][c]+W[a-1][b][c-1]-W[a-1][b-1][c-1];
	}
	// cout << "W(" << a << ", " << b << ", " << c << ") = ";
	// cout << W[a][b][c] << endl;
      }
    }
  }
  while(cin >> a >> b >> c){
    if(a == -1 && b == -1 && c == -1){
      break;
    }
    cout << "w(" << a << ", " << b << ", " << c << ") = " ;
    if(a <= 0 || b <= 0 || c <= 0){
      a = b = c = 0;
    }else if(a > 20 || b > 20 || c > 20){
      a = b = c = 20;
    }
    cout << W[a][b][c] << endl;
  }
}
