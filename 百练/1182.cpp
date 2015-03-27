#include<iostream>
#define A 1
#define B 2
#define C 3
#define U 0

using namespace std;

int catos[50010];
int 

int main(){
  int N, K, D, X, Y;
  cin >> N >> K;
  int r = 0, i;
  for(i = 0; i < K; i++){
    cin >> D >> X >> Y;
    if(X > N || Y > N){
      r++;
    }else if(D == 2 && X == Y){
      r++;
    }else if(D == 1){
      if(catos[X] == catos[Y])
    }
  }
}
