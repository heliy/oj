#include<iostream>
#include<math.h>

using namespace std;

int monthsday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int between(int m1, int d1, int m2, int d2){
  if(m1 == m2){
    return d2 - d1;
  }
  int i, day = monthsday[m1] - d1;
  for(i = m1 + 1; i < m2; i++){
    day += monthsday[i];
  }
  return d2 + day;
}

int main(){
  int n, i;
  cin >> n;
  for(i = 0; i < n; i++){
    int m1, d1, init, m2, d2;
    cin >> m1 >> d1 >> init >> m2 >> d2;
    cout << (long)pow(2, between(m1, d1, m2, d2)) * (long) init << '\n';
  }
  return 0;
}
