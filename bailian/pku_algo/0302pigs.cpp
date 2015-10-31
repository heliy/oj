#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

#define MAX 999999

using namespace std;

int augment(vector<vector<int> >&cap, int begin, int end, vector<int>&prev){
  int minc = -1, c;
  int u, v = end;
  while(v != begin){
    u = prev[v];
    c = cap[u][v];
    if(minc < 0 || c < minc){
      minc = c;
    }
    v = u;
  }
  v = end;
  while(v != begin){
    u = prev[v];
    cap[u][v] -= minc;
    cap[v][u] += minc;
    v = u;
  }
  return minc;
}

int bfs(vector<vector<int> >&cap, int begin, int end){
  int n = cap.size();
  vector<bool> visited(n, false);
  vector<int> prev(n);
  queue<int> q;
  q.push(begin);
  visited[begin] = true;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v = 0; v < n; v++){
      if(!visited[v] && cap[u][v] > 0){
	visited[v] = true;
	prev[v] = u;
	if(v == end){
	  return augment(cap, begin, end, prev);
	}
	q.push(v);
      }
    }
  }
  return 0;
}

int ek(vector<vector<int> >&cap, int begin, int end){
  int flow, max_flow = 0;
  while((flow = bfs(cap, begin, end)) > 0){
    max_flow += flow;
  }
  return max_flow;
}

int main(){
  int m, n;
  cin >> m >> n;
  int i, a, b, k, ki;
  int total = m+n+2;
  vector<vector<int> > cap(total, vector<int>(total));
  vector<int> last(m+1, 0);
  vector<int> st(m+1, 0);
  for(i = 1; i <= m; i++){
    scanf("%d", &a);
    // st[i] = a;
    cap[0][i] = a;
  }
  for(i = 1; i <= n; i++){
    scanf("%d", &a);
    for(ki = 0; ki < a; ki++){
      scanf("%d", &k);
      if(last[k] == 0){
	// cout << "0, " << i << ": " << st[k];
	cap[k][i+m] = MAX;
      }else{
	cap[last[k]+m][i+m] = MAX;
      }
      last[k] = i;
    }
    scanf("%d", &b);
    cap[i+m][total-1] = b;
  }
  // for(i = 0; i < total; i++){
  //   for(s = 0; s < total; s++){
  //     cout << cap[i][s] << " ";
  //   }
  //   cout << endl;
  // }
  cout << ek(cap, 0, total-1) << endl;
}
