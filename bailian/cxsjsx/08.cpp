#include<cstdio>
#include<iostream>
#include<algorithm>

#define N 5001

using namespace std;

int R, C, n;

struct node{
  int x;
  int y;
};

bool cmp(struct node n1, struct node n2){
  if(n1.x != n2.x){
    return (n1.x < n2.x);
  }else{
    return (n1.y < n2.y);
  }
}

int Xindexes[N];

struct node nodes[N];

int next(int a, int b){
  int x, y, i;
  x = (nodes[b].x-nodes[a].x)*2+nodes[a].x;
  y = (nodes[b].y-nodes[a].y)*2+nodes[a].y;
  if(x > R || y > C){
    return -2;
  }
  if(Xindexes[x] < 0){
    return -1;
  }
  for(i = Xindexes[x]; i < n && nodes[i].x == x; i++){
    if(nodes[i].y == y){
      return i;
    }
  }
  return -1;
}

int main(){
  int i, j, x, y, c, maxC;
  cin >> R >> C >> n;
  for(i = 0; i < n; i++){
    scanf("%d %d", &nodes[i].x, &nodes[i].y);
  }
  sort(nodes, nodes+n, cmp);
  for(i = 1; i <= R; i++){
    Xindexes[i] = -1;
  }
  Xindexes[nodes[0].x] = 0;
  for(i = 1; i < n; i++){
    if(nodes[i].x != nodes[i-1].x){
      Xindexes[nodes[i].x] = i;
    }
  }
  if(n == 1){
    maxC = 1;
  }else{
    maxC = 2;
  }
  for(i = 0; i < n; i++){
    bool need = false;
    for(j = i+1; j < n; j++){
      c = 2;
      x = i, y = j;
      do{
	int t = next(x, y);
	if(t >= 0){
	  x = y;
	  y = t;
	  c++;
	  if(c > maxC){
	    maxC = c;
	  }
	}else if(t == -1){
	  break;
	}else{
	  need = true;
	  break;
	}
      }while(true);
      if(need){
	break;
      }
    }
  }
  cout << maxC << endl;
}
