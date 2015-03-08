#include<iostream>

using namespace std;

int nums[41];

int main(){
  int m, n, i, adults = 0, children[3] = {1, 0, 0};
  nums[0] = 1;
  for(i = 1; i <= 40; i++){
    adults += children[2];
    children[2] = children[1];
    children[1] = children[0];
    children[0] = adults;
    nums[i] = (adults+children[0]+children[1]+children[2]);
  }
  cin >> m;
  for(i = 0; i< m; i++){
    cin >> n;
    cout << nums[n] << endl;
  }
}
