#include<iostream>
#include<cstdio>
#include<algorithm>

#define N 30001
#define M 501

using namespace std;

int indexes[N];
int nums[N];

int root(int i){
  if(indexes[i] != i){
    indexes[i] = root(indexes[i]);
  }
  return indexes[i];
}

void uni(int a, int b){
  int r = root(a);
  int s = root(b);
  if(r < s){
    indexes[s] = r;
  }else if(r > s){
    indexes[r] = s;
  }
}

int main(){
  int n, m, i, j, k, l, num;
  while(cin >> n >> m){
    if(n == 0){
      break;
    }
    if(m == 0){
      cout << 1 << endl;
      continue;
    }
    for(i = 0; i < n; i++){
      indexes[i] = i;
    }
    for(i = 0; i < m; i++){
      scanf("%d", &j);
      for(k = 0; k < j; k++){
	scanf("%d", nums+k);
      }
      sort(nums, nums+j);
      for(k = 1; k < j; k++){
	uni(nums[0], nums[k]);
      }
    }
    // for(i = 0; i < n; i++){
    //   cout << indexes[i] << " ";
    // }
    // cout << endl << endl;
    for(i = num = 1; i < n; i++){
      if(root(i) == root(0)){
	num++;
      }
    }
    // for(i = 0; i < n; i++){
    //   cout << indexes[i] << " ";
    // }
    // cout << endl;
    cout << num << endl;
  }
}
