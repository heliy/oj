#include<iostream>

using namespace std;

int nums[610];

int gcd(int a, int b){
  int min = (a>b)?b:a;
  int max = (a<b)?b:a;
  if(min == 0){
    return max;
  }else{
    return gcd(max%min, min);
  }
}

int main(){
  int n, i, j;
  while(cin >> n && n){
    for(i = 0; i < n; i++){
      cin >> nums[i];
    }
    int count = 0;
    for(i = 0; i < n; i++){
      for(j = i+1; j < n; j++){
	if(gcd(nums[i], nums[j]) == 1){
	  count++;
	}
      }
    }
    cout << count << endl;
  }
}
