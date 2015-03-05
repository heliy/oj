#include<iostream>
#include<cstdlib>

using namespace std;

int queenlist[92][8];
int list_num = 0;
int test[8];

void queen(int q){
  int i, j;
   cout << q << endl;
  if(q == 8){
    for(i = 0; i < 8; i++){
      queenlist[list_num][i] = test[i] + 1;
    }
    list_num++;
    return;
  }
  for(j = 0; i < 8; j++){
    for(i = 0; i < q; i++){ // 行固定
      if(test[i] == j || abs(i-q) == abs(test[i]-j)){
	break;
      }
    }
    if(i == q){
      test[q] = j;
      queen(q+1);
    }
  }
}

int main(){
  int n, ni, i, j;
  cin >> n;
  queen(0);
  for(ni = 0; ni < n; ni++){
    cin >> i;
    for(j = 0; j < 8; j++){
      cout << queenlist[i-1][j];
    }
    cout << endl;
  }
}
