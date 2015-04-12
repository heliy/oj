#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  int n, m, i;
  cin >> n >> m;
  if(m == 0){
    for(i = 0; i < n; i++){
      printf("0");
    }
    cout << endl;
  }else if(n < m-1){
    cout << "NO" << endl;
  }else if(n == m-1){
    cout << "1";
    for(i = 0; i < n; i++){
      printf("01");
    }
    cout << endl;
  }else if(n == m){
    for(i = 0; i < n; i++){
      printf("01");
    }
    cout << endl;
  }else{
    for(i = 0; i < m; i++){
      printf("01");
    }
    n -= m;
    for(i = 0; i < n; i++){
      printf("0");
    }
    cout << endl;
  }
}
