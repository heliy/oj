#include<iostream>
#include<algorithm>
#include<cmath>
#define N 1000

using namespace std;

/* TLE */

struct node{
  int x;
  int y;
};

struct node nodes[N];

bool cmp(struct node n1, struct node n2){
  if(n1.x != n2.x){
    return (n1.x < n2.x);
  }else{
    return (n1.y < n2.y);
  }
}

int find(int j, int x, int y, int n){
  int k;
  // cout << x << " " << y << endl;
  for(k = j; k < n; k++){
    // cout << nodes[k].x << " " << nodes[k].y << endl;
    if(nodes[k].x > x && nodes[k].y > y){
      break;
    }
    if(nodes[k].x == x && nodes[k].y == y){
      break;
    }
  }
  // cout << endl;
  return k;
}


int main(){
  int n, x, y, i, j, k, begin;
  while(cin >> n && n){
    for(i = 0; i < n; i++){
      cin >> nodes[i].x >> nodes[i].y;
    }
    sort(nodes, nodes+n, cmp);
    // for(i = 0; i < n; i++){
    //   cout << nodes[i].x << " " << nodes[i].y <<endl;
    // }
    // cout << endl;
    int count = 0;
    for(i = 0; i < n; i++){
      for(j = i+1; j < n; j++){
	if(nodes[j].x < nodes[i].x || nodes[j].y < nodes[i].y){
	  continue;
	}
	int cx = nodes[i].x+(nodes[j].y-nodes[i].y);
	int cy = nodes[i].y+(nodes[i].x-nodes[j].x);
	int dx = cx+(nodes[j].x-nodes[i].x);
	int dy = cy+(nodes[j].y-nodes[i].y);
	// cout << nodes[i].x << " " << nodes[i].y << endl;
	// cout << nodes[j].x << " " << nodes[j].y << endl;
	// cout << cx << " " << cy << endl;
	// cout << dx << " " << dy << endl;
	k = find(i+1, cx, cy, n);
	if(nodes[k].x != cx || nodes[k].y != cy){
	  continue;
	}
	k = find(i+1, dx, dy, n);
	if(nodes[k].x == dx && nodes[k].y == dy){
	  count++;
	}
      }
    }
    cout << count << endl;
  }
}
