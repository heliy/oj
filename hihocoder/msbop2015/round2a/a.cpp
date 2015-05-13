#include<cstdio>
#include<iostream>
#define N 100010

using namespace std;

int parents[N];
int color[N];

int subtrees[N];


int main(){
  int t, ti, n, q, i, a, b, min, max;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    cin >> n;
    for(i = 1; i <= n; i++){
      parents[i] = -1;
      color[i] = 0;
    }
    for(i = 1; i < n; i++){
      scanf("%d %d", &a, &b);
      min = (a < b)?(a):(b);
      max = a+b-min;
      parents[max] = min;
    }
    cout << "Case #" << ti << ":" << endl;
    cin >> q;
    for(i = 0; i < q; i++){
      scanf("%d", &a);
      if(a == 1){
	subtrees[1] = 1;
	for(a = 2; a <= n; a++){
	  if(color[parents[a]] == color[a]){
	    subtrees[a] = subtrees[a-1];
	  }else{
	    subtrees[a] = subtrees[a-1]+1;	    
	  }
	}
	printf("%d\n", subtrees[n]);
      }else{
	scanf("%d %d", &a, &b);
	color[a] = b;
      }
    }
  }
}
