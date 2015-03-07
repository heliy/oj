#include<iostream>
#include<algorithm>
using namespace std;

int graden[3] = {0, 0, 0};
int sorted[3] = {0, 0, 0};
char a[10];

int mark(char *b){
  switch(b[0]){
  case 'r': return 10;
  case 'w': return -10;
  default: return 0;
  }
}

int main(){
  int i, j, n, ni;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    for(i = 0; i < 3; i++){
      cin >> a;
      graden[i] += mark(a);
      sorted[i] += mark(a);
    }
  }
  sort(sorted, sorted+3);
  for(i = 2; i >= 0; i--){
    if(i < 2 && sorted[i] == sorted[i+1]){
      continue;
    }
    for(j = 0; j < 3; j++){
      if(graden[j] == sorted[i]){
	cout << "(" << j+1 << "," << graden[j] << ")";
      }
    }
    cout << endl;
  }
  return 0;
}
