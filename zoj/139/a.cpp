#include<iostream>
#include<cstdio>

using namespace std;

/* AC */

int array[110];

int count(int a, int n){
  int i, c = 0;
  for(i = 0; i < n; i++){
    if(array[i] == a){
      c++;
    }
  }
  return c;
}

int main(){
  int t, ti, n, i;
  cin >> t;
  for(ti = 0; ti < t; ti++){
    cin >> n;
    for(i = 0; i < n; i++){
      scanf("%d", &array[i]);
    }
    int a, b;
    for(i = 1; i < n; i++){
      if(array[i-1] != array[i]){
	a = array[i-1];
	b = array[i];
      }
    }
    if(count(a, n) == 1){
      cout << a << endl;
    }else{
      cout << b << endl;
    }
  }
}
