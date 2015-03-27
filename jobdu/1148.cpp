#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  double sum, month;
  while(cin >> sum){
    int i;
    for(i = 0; i < 11; i++){
      cin >> month;
      sum += month;
    }
    sum /= 12;
    // cout << sum << endl;
    // cout << (sum*100-(int(sum*100))) <<  endl;
    cout << "$";
    printf("%.2f", sum);
    cout << endl;
  }
}
