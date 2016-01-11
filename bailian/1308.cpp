#include<iostream>
#define N 999

using namespace std;

int catos[N];
bool canber[N];
bool used[N];

int find(int i){
  if(catos[i] != i){
    catos[i] = find(catos[i]);
  }
  return catos[i];
}

void uni(int a, int b){
  int r = find(a);
  int s = find(b);
  if(r < s){
    catos[s] = r;
  }else{
    catos[r] = s;
  }
}

int main(){
  int a, b, r, e, n, i, t=1;
  bool is_tree;
  n = 0;
  for(i = 0; i < N; i++){
    catos[i] = i;
    used[i] = false;
    canber[i] = true;
  }
  while(cin >> a >> b){
    if(a == -1 && b == -1){
      break;
    }else if(a == 0 && b == 0){
      r = -1;
      for(i = 0; i < N; i++){
	if(used[i] && canber[i]){
	  r = i;
	  break;
	}
      }
      e = -1;
      for(i = r+1; i < N; i++){
	if(used[i] && canber[i]){
	  e = i;
	  break;
	}
      }
      if(r != -1 && e == -1){
	int s = find(r);
	for(b = a = 0; a < N; a++){
	  if(used[a] && find(a) == s){
	    b++;
	  }
	}
	if(b == n+1){
	  is_tree = true;
	}else{
	  is_tree = false;
	}
      }else{
	is_tree = false;
      }
      if(n == 0){
	is_tree = true;
      }
      cout << "Case " << t << " is ";
      if(!is_tree){
	cout << "not ";
      }
      cout << "a tree.\n";
      t++;
      n = 0;
      for(i = 0; i < N; i++){
	catos[i] = i;
        used[i] = false;
        canber[i] = true;
      }
      is_tree = true;
    }else{
      n++;
      used[a] = used[b] = true;
      canber[b] = false;
      uni(a, b);
    }
  }
}
