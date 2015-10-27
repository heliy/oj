#include<iostream>

using namespace std;

int days[13] = {
  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

int main(){
  int w, d, i, total;
  int months[13];
  cin >> w;
  for(i = 0; i < 13; i++){
    months[i] = 0;
  }
  d = 13 - (8-w);
  total = 0;
  for(i = 1; i < 13; i++){
    d += days[i-1];
    if(d%7 == 5){
      months[i] = 1;
      total++;
    }
  }
  for(i = 1; i < 13; i++){
    if(months[i] == 1){
      cout << i << '\n';
    }
  }
  return 0;
}
