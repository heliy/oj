#include<iostream>
#define N 210

using namespace std;

int dits[N];
int sum[N];
char line[N];

int main(){
  int n, B;
  while(cin >> n >> B){
    int ni, i, j;
    for(i = 0; i < N; i++){
      sum[i] = 0;
    }
    for(ni = 0; ni < n; ni++){
      cin >> line;
      for(i = 0; i < N; i++){
        dits[i] = 0;
      }
      for(i = 0; line[i] != '\0'; i++);
      for(j = 0, i--; i >= 0; i--,j++){
	if(line[i] >= '0' && line[i] <= '9'){
	  dits[j] = line[i] - '0';
	}else{
	  dits[j] = line[i] - 'a' + 10;
	}
      }
      for(i = 0; i < N; i++){
	sum[i] = (sum[i]+dits[i])%B;
      }
    }
    for(i = N; i >= 0 && sum[i] == 0; i--);
    for(; i >= 0; i--){
      if(sum[i] > 9){
	char c = 'a' + sum[i] - 10;
        cout << c;
      }else{
	cout << sum[i];
      }
    }
    cout << endl;
  }
}
