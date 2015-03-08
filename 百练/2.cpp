#include<iostream>

using namespace std;

int sum[110], num[110];
char line[110];

void print(int*a){
  int i;
  for(i = 109; i >= 0; i--){
    if(sum[i] != 0){
      break;
    }
  }
  for(; i >= 0; i--){
    cout << a[i];
  }
  cout << endl;  
}
int main(){
  int i, j;
  for(j = 0; j < 110; i--, j++){
    sum[j] = 0;
  }
  while(cin >> line){
    for(i = 0; line[i] != '\0'; i++);
    for(j = 0; j < 110; j++){
      num[j] = 0;
    }
    for(j = 0, i--; i >= 0; i--, j++){
      num[j] = line[i]-'0';
    }
    for(i = 0; i < 110; i++){
      sum[i] += num[i];
      if(i > 0 && sum[i-1] > 9){
	sum[i-1] %= 10;
	sum[i]++;
      }
    }
  }
  print(sum);
}
