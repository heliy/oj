#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#define N 202

using namespace std;

int augment(vector<vector<int> > &cap, int s, int t, const vector<int> &p){
  int bt = -1, v = t;
  while(v != s){
    int u = p[v];
    int c = cap[u][v];
    if(bt < 0 || c < bt){
      bt = c;
    }
    v = u;
  }
  v = t;
  while(v != s){
    int u = p[v];
    cap[u][v] -= bt;
    cap[v][u] += bt;
    v = u;
  }
  return bt;
}

int bfs(vector<vector<int> > &cap, int s, int t){
  int n = cap.size();
  vector<bool> visited(n, false);
  vector<int> p(n);
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v = 0; v < n; v++){
      if(!visited[v] && cap[u][v] > 0){
	visited[v] = true;
	p[v] = u;
	if(v == t){
	  return augment(cap, s, t, p);
	}
	q.push(v);
      }
    }
  }
  return 0;
}

int ek(vector<vector<int> > &cap, int s, int t){
  int flow, maxFlow = 0;
  while((flow = bfs(cap, s, t)) > 0){
    maxFlow += flow;
  }
  return maxFlow;
}

int main(){
  int n, m, i, j, c, a, b;
  while(cin >> m >> n){
    vector<vector<int> > cap(n+1, vector<int>(n+1));
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &a, &b, &c);
      cap[a][b] += c;
    }
    cout << ek(cap, 1, n) << endl;
  }
}
