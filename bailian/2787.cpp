#include<iostream>
#define abs(A) (((A)<0)?(-1*(A)):(A))

using namespace std;

int querry[4];

bool can(double, int);

bool next(int t, int q, int i){
  bool b= (can(t+querry[i/2], q+i) || can(t*querry[i/2], q+i) ||
	   can(t-querry[i/2], q+i) || can(querry[i/2]-t, q+i));
  if(!t){
    b = (b || can(querry[i/2]/t, q+i));
  }
  if(!querry[i/2]){
    b = (b || can(t/querry[i/2], q+i));
  }
  return b;
}

bool can(double t, int q){
  if(q == 15 && abs(t-24) < 0.0000000000001){
    return true;
  }
  int i;
  for(i = 1; i < 16; i *= 2){
    cout << t << "," << i << endl;    
    if(!(q&i) && next(t, q, i)){
      return true;
    }
  }
  return false;
}

int main(){
  int a;
  while(cin >> a && a){
    querry[0] = a;
    cin >> querry[1] >> querry[2] >> querry[3];
    if(can(0, 0)){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
}
