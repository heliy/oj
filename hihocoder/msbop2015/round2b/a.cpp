#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 53
//#define MOD 18446744073709551616L

using namespace std;

int cards[N];
int c;
int nums[N];

int isok(int n){
  int i;
  for(i = 0; i < n; i++){
    if(i > 0){
      if(cards[i] == cards[i-1]){
	return 0;
      }
    }
    if(i < n-1){
      if(cards[i] == cards[i+1]){
	return 0;
      }
    }
  }
  return 1;
}

int order(int n){
  sort(cards, cards+n);
  c = isok(n);
  while(next_permutation(cards, cards+n)){
    c += isok(n);
  }
  return c;
}

int p(int n){
  int i, c = 1;
  for(i = n; i > 1; i--){
    c *= i;
  }
  return c;
}

int value(char c){
  if(c >= '2' && c <= '9'){
    return c-'0';
  }
  switch(c){
  case 'T': return 10;
  case 'J': return 11;
  case 'Q': return 12;
  case 'K': return 13;
  case 'A': return 1;
  default: return -1;
  }
}

int main(){
  int cases, ti, n, i, v;
  char line[N*2];
  cin >> cases;
  for(ti = 1; ti <= cases; ti++){
    scanf("%d", &n);
    fgets(line, N*2, stdin);
    for(i = 0; i < 20; i++){
      nums[i] = 0;
    }
    for(i = 0; i < n; i++){
      cards[i] = value(line[i*3+1]);
      nums[cards[i]]++;
    }
    int st = 1;
    for(i = 0; i < 20; i++){
      if(nums[i] > 1){
	st *= p(nums[i]);
      }
    }
    // st = (st == 0)?(1):(st);
    // cout << st << endl;
    printf("Case #%d: %d\n", ti, order(n)*st);
  }
}
