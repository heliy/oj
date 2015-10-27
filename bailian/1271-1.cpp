#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

char line[50];

int main(){
  long long dec;
  while(cin >> line && line[0] != '0'){
    int len = strlen(line);
    long long i;
    dec = 0;
    for(len--, i = 2; len >= 0; len--, i *= 2){
      dec += (line[len]-'0')*(i-1);
    }
    cout << dec << endl;
  }
}
