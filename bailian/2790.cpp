#include<cstdio>

using namespace std;

int laby[102][102];
int walk[102][102];
int used[102][102];

void take(int i, int j){
  if(used[i][j]){
    return;
  }
  if(laby[i][j]){
    used[i][j] = 1;
    return;
  }
  walk[i][j] = 1;
  used[i][j] = 1;
  take(i-1, j);
  take(i+1, j);
  take(i, j-1);
  take(i, j+1);
}

int main(){
  int k, ki;
  scanf("%d", &k);
  for(ki = 0; ki < k; ki++){
    int n, i, j;
    char c;
    for(i = 0; i < 102; i++){
      for(j = 0; j < 102; j++){
	laby[i][j] = 1;
	walk[i][j] = 0;
	used[i][j] = 0;
      }
    }
    scanf("%d", &n);
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	c = ' ';
	while(c != '.' && c != '#'){
	  scanf("%c", &c);
	}
	if(c == '.'){
	  laby[i][j] = 0;
	}
      }      
    }
    int fromi, fromj, toi, toj;
    scanf("%d %d %d %d", &fromi, &fromj, &toi, &toj);
    take(fromi, fromj);
    if(walk[toi][toj]){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}
