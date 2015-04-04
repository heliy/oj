#include<iostream>
#include<cstring>

using namespace std;

int cases[1000];
char line[1010];

int main(){
  int t, ti, n, ni, i, j, f;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n;
    f = 0;
    for(ni = 0; ni < n; ni++){
      cin >> line;
      i = strlen(line);
      if(i > f){
	f = i;
      }
      cases[ni] = i;
    }
    if(f%2 == 0){
      f /= 2;
    }else{
      f = f/2+1;
    }
    for(ni = 0; ni < n; ni++){
      if(cases[ni] >= f){
	cases[ni] = 1;
      }else{
	cases[ni] = 0;
      }
    }
    ni = 0;
    while(ni < n && cases[ni] == 0){
      ni++;
    }
    i = ni;
    ni = n-1;
    while(ni >= 0 && cases[ni] == 0){
      ni--;
    }
    j = ni;
    cout << j-i+1 << endl;
  }
}
