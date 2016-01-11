#include<iostream>
#define A 1
#define B 2
#define C 3
#define U 0

using namespace std;

int catos[50010];

int find(int i){
  if(catos[i] = -1){
    return -1;
  }
  if(catos[i] != i){
    catos[i] = find(catos[i]);
  }
  return catos[i];
}

void unit(int a, int b){
  int r = find(a);
  int s = find(b);
  if(r == -1 && s == -1){
    if(a < b){
      catos[b] = a;
      catos
    }
  }
  if(r < s){
    catos[s] = r;
  }else{
    catos[r] = s;
  }
}

int main(){
  int N, K, D, X, Y;
  cin >> N >> K;
  int r = 0, i;
  for(i = 0; i < N; i++){
    catos[i] = -1;
  }
  for(i = 0; i < K; i++){
    cin >> D >> X >> Y;
    if(X > N || Y > N){
      r++;
    }else if(D == 2){
      if(X == Y){
	r++;
      }
      if(find(X) == -1 && find(Y) == -1){
	
      }
    }
    }else if(D == 1){
      if(catos[X] == catos[Y])
    }
  }
}
