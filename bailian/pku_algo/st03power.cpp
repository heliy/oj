#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>
#include<iostream>

#define N (204+4)
#define M (N*N+4*N)

typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

/*
 * When there are multiple test sets, you need to re-initialize before each
 */
void dinic_init(void) {
  num_of_edges = 0;
  memset(head, -1, sizeof(head));
  return;
}

int add_edge(int u, int v, int c1, int c2) {
  int& i=num_of_edges;

  assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
  e[i].v = v;
  e[i].cap = c1;
  e[i].next = head[u];
  head[u] = i++;

  e[i].v = u;
  e[i].cap = c2;
  e[i].next = head[v];
  head[v] = i++;
  return i;
}

void print_graph(int n) {
  for (int u=0; u<n; u++) {
    printf("%d: ", u);
    for (int i=head[u]; i>=0; i=e[i].next) {
      printf("%d(%d)", e[i].v, e[i].cap);
    }
    printf("\n");
  }
  return;
}

/*
 * Find all augmentation paths in the current level graph
 * This is the recursive version
 */
int dfs(int u, int t, int bn) {
  if (u == t) return bn;
  int left = bn;
  for (int i=cur[u]; i>=0; i=e[i].next) {
    int v = e[i].v;
    int c = e[i].cap;
    if (c > 0 && level[u]+1 == level[v]) {
      int flow = dfs(v, t, min(left, c));
      if (flow > 0) {
        e[i].cap -= flow;
        e[i^1].cap += flow;
        cur[u] = i;
        left -= flow;
        if (!left) break;
      }
    }
  }
  if (left > 0) level[u] = 0;
  return bn - left;
}

bool bfs(int s, int t) {
  memset(level, 0, sizeof(level));
  level[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return true;
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (!level[v] && e[i].cap > 0) {
        level[v] = level[u]+1;
        q.push(v);
      }
    }
  }
  return false;
}

LL dinic(int s, int t) {
  LL max_flow = 0;

  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    max_flow += dfs(s, t, INT_MAX);
  }
  return max_flow;
}

int upstream(int s, int n) {
  int cnt = 0;
  vector<bool> visited(n);
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (e[i].cap > 0 && !visited[v]) {
        visited[v] = true;
        q.push(v);
        cnt++;
      }
    }
  }
  return cnt; // excluding s
}

int mat[N][N];

int main(){
    int n, np, nc, m, i, j, u, v ,z;
    char c;
    while(cin >> n >> np >> nc >> m){
              memset(mat, 0, sizeof(mat));
              dinic_init();
              for(i = 0; i < m; i++){
                    c = '-';
                    while(c != '('){
                            scanf("%c", &c);
                    }
                    scanf("%d,%d)%d", &u, &v, &z);
                    mat[u+1][v+1] = z;
//                    cout << u << v << z;
//                    add_edge(u+1, v+1, z, 0);
              }
              for(i = 0; i < np; i++){
                    c = '-';
                    while(c != '('){
                            scanf("%c", &c);
                    }
                    scanf("%d)%d", &u, &z);
                    mat[0][u+1] = z;
//                    add_edge(0, u+1, z, 0);
              }
              for(i = 0; i < nc; i++){
                    c = '-';
                    while(c != '('){
                            scanf("%c", &c);
                    }
                    scanf("%d)%d", &u, &z);
                    mat[u+1][n+1] = z;
//                    add_edge(u+1, n+1, z, 0);
              }
              for(i = 0; i < n+2; i++){
                    for(j = 0; j < n+2; j++){
                          if(mat[i][j] > 0){
                                       add_edge(i, j, mat[i][j], 0);
                          }
                    }
              }
//              print_graph(n+2);
              LL flow = dinic(0, n+1);
              cout << flow << "\n";
    }
//    system("pause");
}
