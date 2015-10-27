#include<iostream>
#include<cstring>

using namespace std;

int sum[202];
int a[202];
int b[202];
char line1[202];
char line2[202];

int main(){
  cin >> line1 >> line2;
  int a_len, b_len, i, j;
  for(i = 0; i < 202; i++){
    a[i] = 0;
    b[i] = 0;
    sum[i] = 0;
  }

  a_len = strlen(line1);
  b_len = strlen(line2);
  for(i = a_len-1, j =0 ; i >= 0; i--, j++){
    a[j] = line1[i] - '0';
  }
  for(i = b_len-1, j =0 ; i >= 0; i--, j++){
    b[j] = line2[i] - '0';
  }

  for(i = 0; i <= 200; i++){
    sum[i] += a[i] + b[i];
    if(sum[i] > 9){
      sum[i] -= 10;
      sum[i+1]++;
    }
  }

  for(i = 201; i >= 0 && sum[i] == 0; i--)
    ;
  if(i == -1){
    cout << 0;
  }
  for(j = i; j >= 0; j--){
    cout << sum[j];
  }
  cout << endl;
}
