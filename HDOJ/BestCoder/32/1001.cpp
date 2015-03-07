#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct city{
  int first;
  int second;
  int div;
  int n;
  int rank;
};

bool cmp1(struct city city1, struct city city2){
  if(city1.div != city2.div){
    return (city1.div > city2.div);
  }
  if(city1.second != city2.second){
    return (city1.second < city2.second);
  }else{
    return (city1.n < city2.n);
  }
}

struct city citys[110];

int main(){
  int n;
  while(cin >> n){
    int i;
    for(i = 0; i < n; i++){
      cin >> citys[i].first >> citys[i].second;
      citys[i].div = citys[i].first - citys[i].second;
      citys[i].n = i;
    }
    sort(citys, citys+n, cmp1);
    for(i = 0; i < n; i++){
      citys[i].rank = i;
    }
    for(i = 0; i < n; i++){
      cout << citys[i].n;
      if(i < n-1){
	cout << " ";
      }
    }
    cout << endl;
  }
}
