#include<iostream>
#include<cstdio>
#include<vector>
#define N 101

using namespace std;

bool isVisited[N];
int ins[N];
int n;

vector<vector<int> > graph;
int result[N];

void printins(){
  int i;
  cout << endl;
  cout << "Ins: ";
  for(i = 0; i < n; i++){
    cout << ins[i] << " ";
  }
  cout << endl;
  cout << "Out: ";
  for(i = 0; i < n; i++){
    cout << graph[i].size() << " ";
  }
  cout << endl;
}

void printresult(){
  int i;
  for(i = 0; i < n-1; i++){
    cout << result[i] << " ";
  }
  cout << result[n-1] << "\n";
}

bool isOK; 			// 只要输出1个就可以！

void top(int res){
  if(res == 0 || isOK){
    return;
  }

  int m, i;
  vector<int> can;
  for(i = 0; i < n; i++){
    if(ins[i] == 0 && !isVisited[i]){
      can.push_back(i);
    }
  }
  for(i = 0; i < can.size(); i++){
    result[n-res] = can[i]+1;
    if(res == 1){
      printresult();
      isOK = true;
      return;
    }else{
      isVisited[can[i]] = true;
      // cout << (can[i]+1);
      // printins();
      // cout << graph[can[i]].size() << endl;
      for(m = 0; m < graph[can[i]].size(); m++){
	ins[graph[can[i]][m]]--;
      }
      // printins();
      top(res-1);
      isVisited[can[i]] = false;
      for(m = 0; m < graph[can[i]].size(); m++){
	ins[graph[can[i]][m]]++;
      }
    }
  }
}

int main(){
  int i, m;
  cin >> n;
  graph.resize(n);
  for(i = 0; i < n; i++){
    while(true){
      cin >> m;
      if(m != 0){
	graph[i].push_back(m-1);
	ins[m-1]++;
      }else{
	break;
      }
    }
  }
  isOK = false;
  top(n);
}
