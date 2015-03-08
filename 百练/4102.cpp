#include<iostream>

using namespace std;

struct tale{
  int need;
  int hhp;
};

struct tale tales[100];

int Max[100][100][3];

void print(int k){
  int i, j;
  for(i = 0; i <= k; i++){
    for(j = 0; j <= k; j++){
      cout << Max[i][j][0] << "," << Max[i][j][1] << "," << Max[i][j][2] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}

int plans[2][4];

int main(){
  int n, m, k, i, j, target;
  cin >> n >> m >> k;
  for(i = 1; i <= k; i++){
    cin >> tales[i].need >> tales[i].hhp;
  }
  for(i = 0; i < 100; i++){
    Max[i][0][0] = Max[0][i][0] = 0;
    Max[i][0][1] = Max[0][i][1] = m;
    Max[i][0][2] = Max[0][i][2] = n;
  }
  for(i = 1; i <= k; i++){
    for(j = 1; j <= i; j++){
      for(target = j; target >= 0; target--){
        int len = 0;
      // cout << i << ": " << tales[i].hhp << endl;
        if(tales[i].need <= Max[i-1][target-1][2] && tales[i].hhp <= Max[i-1][target-1][1]){
          plans[len][0] = Max[i-1][target-1][0]+1;
      	  plans[len][1] = Max[i-1][target-1][1] - tales[i].hhp;
      	  plans[len][2] = Max[i-1][target-1][2] - tales[i].need;
      	  plans[len][3] = 1;
      	  len++;
        }
        plans[len][0] = Max[i-1][target][0];
        plans[len][1] = Max[i-1][target][1];
        plans[len][2] = Max[i-1][target][2];
        plans[len][3] = 2;
        len++;
        int plan = 0, d = 0;
	cout << plans[d][0] << "," << plans[d][1] << ',' << plans[d][2] << endl;
        for(d = 1; d < len; d++){
	  cout << plans[d][0] << "," << plans[d][1] << ',' << plans[d][2] << endl;
          if(plans[d][0] >= plans[plan][0] && plans[d][1] > plans[plan][1]){
            plan = d;
          }
        }
        cout << plans[plan][3] << endl;
	if(plans[plan][0] == target){
          Max[i][j][0] = plans[plan][0];
          Max[i][j][1] = plans[plan][1];
          Max[i][j][2] = plans[plan][2];
          print(k);
	  break;
	}
      }
    }
  }
  for(j = k; j > 0; j--){
    if(Max[k][j][0] != 0){
      cout << Max[k][j][0] << " " << Max[k][j][1] << endl;
      return 0;
    }
  }
  cout << 0 << " " << m << endl;
}
