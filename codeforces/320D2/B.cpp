#include<iostream>
#include<cstdio>
#include<algorithm>

# define N 401
using namespace std;


struct link{
  int i;
  int j;
  int l;
};

bool cmp(struct link l1, link l2){
  return (l1.l > l2.l);
}

struct link links[N*N/2+2];
int pars[N*2+2];

int main(){
  int n, i, j, l, k = 0, d;
  cin >> n;
  n *= 2;
  for(i = 2; i <= n; i++){
    for(j = 1; j < i; j++){
      cin >> l;
      links[k].i = i;
      links[k].j = j;
      links[k++].l = l;
    }
  }
  sort(links, links+k, cmp);
  for(i = 1; i <= n; i++){
    pars[i] = -1;
  }
  for(l = d = 0; l < k; l++){
    i = links[l].i;
    j = links[l].j;
    // cout << l << ": " << i << ", " << j << endl;
    if(pars[i] == -1 && pars[j] == -1){
      pars[i] = j;
      pars[j] = i;
      d++;
      if(d == n){
	break;
      }
    }
  }
  cout << pars[1];
  for(i = 2; i <= n; i++){
    cout << " " << pars[i];
  }
  cout << endl;
}
