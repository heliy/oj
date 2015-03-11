#include<iostream>
#define N 520

using namespace std;

int m[N][N];

struct node{
  int type;
  int i1;
  int i2;
  int j1;
  int j2;

};

struct node nodes[N*N];
int num = 0;

void tobits(int index){
  int i, j;
  bool haszero , hasone;
  hasezero = hasone = false;
  for(i = nodes[index].i1; i <=  nodes[index].i2; i++){
    for(j = nodes[index].j1; j <= nodes[index].j2; j++){
      if(m[i][j] == 1){
	hasone = true;
      }else{
	haszero = true;
      }
    }
  }
  if(haszero && hasone){
    nodes[index].type = 1;
    num += 4;
nodes[index].
  }
}

int main(){
  int k, ki, n, i, j;
  cin >> k;
  for(ki = 0; ki < k; ki++){
    cin >> n;
    for(i = 1; i <= n; i++){
      for(j = 1; j <= n; j++){
	cin >> m[i][j];
      }
    }
    nodes[0].i1 = nodes[0].j1 = 1;
    nodes[0].i2 = nodes[0].j2 = n;
    tobits(0);
  }
}
