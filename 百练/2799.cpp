#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

char nums[10001][50];
int bs[10001];

int main(){
  int i, max = 0, n;
  cin >> n;
  fgets(nums[0], 50, stdin);
  for(i = 0; i < n; i++){
    fgets(nums[i], 50, stdin);
    int thismax = 0;
    for(thismax = 0; nums[i][thismax] != '.'; thismax++)
      ;
    bs[i] = thismax;
    if(thismax > max){
      max = thismax;
    }
  }
  for(i = 0; i < n; i++){
    int j = (nums[i] < 0) ? 1 : 0;
    for(; j < (max - bs[i]); j++){
      cout << ' ';
    }
    cout << nums[i];
  }
  printf("\n");
  return 0;
}
