#include<cstdio>
#include<iostream>
#define N 1001

using namespace std;

int childs_num[N];

int exp[N];

bool is_exp(int n){
  int i;
  for(i = 0; i < n; i++){
    if(exp[i] == n){
      return true;
    }else if(exp[i] > n){
      return false;
    }
  }
}

int main(){
  int n, u, v, i, j, t;
  exp[0] = 2;
  for(i = 0; exp[i] < N; i++){
    exp[i+1] = exp[i]*2;
  }
  while(cin >> n){
    cout << n << endl;
    for(i = 0; i <= n; i++){
      childs_num[i] = 0;
    }
    for(j = 1; j < n; j++){
      scanf("%d %d", &u, &v);
      if(u > v){
	t = u; u = v; v = t;
      }
      childs_num[u]++;
    }
    if(!is_exp(n+1)){
      printf("NO\n");
    }else{
      for(i = 1; i <= n; i++){
	cout << i << ": " << childs_num[i] << endl;
        if(childs_num[i] == 1){
	  printf("NO\n");
	  break;
        }
      }
      cout << i << endl;
      if(i == n+1){
        printf("YES\n");
      }
    }
  }
}
