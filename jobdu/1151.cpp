#include<iostream>

using namespace std;

int a[16];
int b[16];

void print(int k[16]){
  int i;
  for(i = 0; i < 16; i++){
    cout << k[i];
  }
  cout << endl;
}

void shift(){
  int t = b[15], i;
  for(i = 15; i > 0; i--){
    b[i] = b[i-1];
  }
  b[0] = t;
}

bool issame(){
  int i;
  for(i = 0; i < 16; i++){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

void tobina(int n, int a[16]){
  int i;
  for(i = 0; i < 16; i++){
    a[i] = n%2;
    n = n/2;
  }
}

bool canleftshift(int x, int y){
  tobina(x, a);
  tobina(y, b);
  int i = 16;
  while(i > 0){
    i--;
    if(issame()){
      return true;
    }
    shift();
  }
  return false;
}

int main(){
  int n, x, y, i;
  cin >> n;
  while(n > 0){
    n--;
    cin >> x >> y;
    if(canleftshift(x, y)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}
