#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

stack<char> s;

char line[100000];

int n;

long long maji(int n, int m){
  long long s = 0;
  int i;
  if(m > n || m < 0 || n == 0){
    return 0;
  }else if(n == m || n == 2){
    s = 1; // 全为)
    s = 1; // )) 或 ()
    return 1;
  }else if(m == 0){
    // ((()___
    for(i = 2; i <= n; i++){
      s += maji(n-i, m+i-2);
    }
    cout << n << ", " << m << ": " << s << endl;
  }else{
    // )))(___
    for(i = 0; i <= m; i++){
      s += maji(n-i-1, m-i);
    }
    cout << n << ", " << m << ": " << s << endl;
  }
  return s%1000000007;
}

int main(){
  while(cin >> n){
    fgets(line, 1000000, stdin);
    fgets(line, 1000000, stdin);
    int i, mae, l;
    for(i = 0; line[i] != '\n' && line[i] != '\0'; i++){
      if(line[i] == '('){
	s.push('(');
      }else{
	s.pop();
      }
    }
    l = i;
    mae = s.size();
    for(i = 0; i < mae; i++){
      s.pop();
    }
    cout << maji(n-l, mae) << endl;
  }
}
