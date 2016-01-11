#include<iostream>
#include<cstdio>
#define N 20

using namespace std;

int a[N];
int b[N];
int s[N];
int tmp[N];
char line[N*3];

void reverse(int* l, int n){
  int i;
  for(i = 0; i < n; i++){
    tmp[n-i-1] = l[i];
  }
  for(i = 0; i < n; i++){
    l[i] = tmp[i];
  }
}

int main(){
  int n, i, j, k, d1, d2;
  char c = '.';
  cin >> n;
  for(k = 0; k < n; k++){
    i = 0;
    cin >> line;
    for(j = 0; line[j] == '0'; j++)
      ;
    for(i = j; line[i] >= '0' && line[i] <= '9'; i++){
      a[i-j] = line[i] - '0';
    }
    d1 = i-j;
    cin >> line;
    for(j = 0; line[j] == '0'; j++)
      ;
    for(i = j; line[i] >= '0' && line[i] <= '9'; i++){
      b[i-j] = line[i] - '0';
    }
    d2 = i-j;
    j = i = 0;    
    while(i < d1 && i < d2){
      s[i] = a[i]+b[i]+j;
      j = s[i]/10;
      s[i] %= 10;
      i++;
    }
    while(i < d1){
      s[i] = a[i]+j;
      j = s[i]/10;
      s[i] %= 10;
      i++;
    }
    while(i < d2){
      s[i] = b[i]+j;
      j = s[i]/10;
      s[i] %= 10;
      i++;
    }
    if(j > 0){
      s[i++] = j;
    }
    for(j = 0; j < i; j++){
      if(s[j] != 0){
	break;
      }
    }
    for(; j < i; j++){
      cout << s[j];
    }
    cout << "\n";
  }
}
