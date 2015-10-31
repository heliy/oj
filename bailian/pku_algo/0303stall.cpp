#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int augment(vector<vector<int> > &cap, int begin, int end, vector<int> &prev){
  int minc = -1, c, u, v;
  v = end;
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

int bfs(vector<vector<int> > &cap, int begin, int end){
  int n = cap.size(), u, v;
  vector<bool> isvisited(n, false);
  vector<int> prev(n);
  queue<int> q;
  q.push(begin);
  isvisited[begin] = true;
  while(!q.empty()){
    u = q.front();
    q.pop();
    for(v = 0; v < n; v++){
      if(!isvisited[v] && cap[u][v] > 0){
	prev[v] = u;
	if(v == end){
	  return augment(cap, begin, end, prev);
	}
	isvisited[v] = true;
	q.push(v);
      }
    }
  }
  return 0;
}

int ek(vector<vector<int> > &cap, int begin, int end){
  int flow, max_flow = 0;
  while((flow = bfs(cap, begin, end)) > 0){
    max_flow += flow;
  }
  return max_flow;
}

int main(){
  int m, n, i, j, s, si, k;
  while(cin >> n >> m){
    int total = m+n+2;
    vector<vector<int> > cap(total, vector<int>(total));
    for(i = 1; i <= n; i++){
      cap[0][i] = 1;
    }
    for(i = 1; i <= m; i++){
      cap[i+n][total-1] = 1;
    }
    for(i = 1; i <= n; i++){
      cin >> s;
      for(j = 0; j < s; j++){
	scanf("%d", &si);
	cap[i][n+si] = 1;
      }
    }
    cout << ek(cap, 0, total-1) << endl;
  }
}
