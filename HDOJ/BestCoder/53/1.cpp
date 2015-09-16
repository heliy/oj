#include<cstdio>
#include<iostream>
#define N 101

using namespace std;

int matrix[N][N];
int array[N][N];
int adjcents[N];

bool isused[N];
int leng[N];
int roads[N];

int next[N];
int kan[N];

int main(){
  int n, m, u, v, i, j, nn, k, l;
  while(cin >> n >> m){
    for(i = 1; i <= n; i++){
      isused[i] = false;
      adjcents[i] = leng[i] = roads[i] = 0;
      for(j = 1; j <= n; j++){
	matrix[i][j] = false;
      }
    }
    for(i = 0; i < m; i++){
      scanf("%d %d", &u, &v);
      array[u][adjcents[u]++] = v;
      array[v][adjcents[v]++] = u;
      matrix[u][v] = matrix[v][u] = true;
    }
    isused[1] = true;
    roads[1] = 1;
    leng[1] = l = 0;
    for(i = 0; i < adjcents[1]; i++){
      next[i] = array[1][i];
    }
    nn = i;

    while(!isused[n]){
      l++;
      k = 0;
      cout << nn << endl;
      for(i = 1; i <= nn; i++){
	if(isused[next[i]]){
	  continue;
	}
	kan[k++] = next[i];
      }
      for(; k >= 0; k--){
	j = kan[k];
	leng[j] = l;

	for(i = 0; i <= adjcents[j]; i++){
	  if(leng[array[j][i]] == l-1){
	    roads[j] += roads[array[j][i]];
	  }
	}
      }
      for(i = 1; i <= n; i++){
	if(leng[i] == l){
	  isused[i] = true;
	}
      }
      for(nn = 0, i = 1; i <= n; i++){
	if(leng[i] == l){
	  for(j = 0; j <=  adjcents[i]; j++){
	    if(!isused[array[i][j]]){
	      next[nn++] = array[i][j];
	    }
	  }
	}
      }
    }
    cout << leng[n] << " " << roads[n] << endl;
  }

}
