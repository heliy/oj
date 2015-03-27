#include<iostream>
#include<cstdlib>
#include<cstdio>
#define N 1000
#define M 1000
using namespace std;

int pis[N];
int iris[N];
char cris[N];

int p, r;
char line[N];
char w[M*N], u[M*N], v[M*N];

int build(char*a, int begin, int end){
  int i, j, k, l;
  for(l = 0, i = begin; i < end; i++){
    if(pis[i] == 0){
      a[l++] = cris[i];
    }else{
      for(j = l-pis[i], k = 0; j >= 0 && k < iris[i]; k++, j++){
	a[l++] = a[j];
      }
    }
  }
  // cout << begin << ", " << end << ": ";
  // for(i = 0; i < l; i++){
  //   cout << a[i];
  // }
  // cout << endl;
  return l;
}

bool issame(int wl, int ul, int vl){
  int i, j;
  for(i = ul; i < wl; i++){
    if(w[i] != v[i-ul]){
      return false;
    }
  }
  return true;
}

void pro(int n){
  int i;
  int wl = build(w, 0, n);
  int count = 0;
  for(i = 1; i < n; i++){
    if(pis[i] == 0){
      int ul = build(u, 0, i);
      int vl = build(v, i, n);
      if(issame(wl, ul, vl)){
	count++;
      }
    }	
  }
  cout << count << endl;
}

int main(){
  int i, j, n = 0;
  while(fgets(line, N, stdin) != NULL){
    if(line[0] == '\n' || line[0] == '\0'){
      pro(n);
      n = 0;
    }else{
      if(line[0] == '0'){
	sscanf(line, "0 %c", &cris[n]);
	iris[n] = -1;
	pis[n] = 0;
      }else{
	sscanf(line, "%d %d", &pis[n], &iris[n]);
	cris[n] = '\0';
      }
      n++;
    }
  }
  if(n > 0){
    pro(n);
  }
  return 0;
}
