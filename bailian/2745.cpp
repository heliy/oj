#include<iostream>

using namespace std;

int shus[10][4] = {
  1, 1, 1, 1,
  0, 1, 0, 1,
  0, 1, 1, 0,
  0, 1, 0, 1,
  1, 1, 0, 1,
  1, 0, 0, 1,
  1, 0, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  1, 1, 0, 1,
};

int hens[10][3] = {
  1, 0, 1,
  0, 0, 0,
  1, 1, 1,
  1, 1, 1,
  0, 1, 0,
  1, 1, 1,
  1, 1, 1,
  1, 0, 0,
  1, 1, 1,
  1, 1, 1,
};

void printhen(char* a, int s, int k){
  int i;
  for(i = 0; a[i] != '\0' ; i++){
    int n = a[i] - '0';
    char c;
    if(i != 0){
      cout << ' ';
    }
    cout << ' ';
    if(hens[n][k] == 1){
      c = '-';
    }else{
      c = ' ';
    }
    int j;
    for(j = 0; j < s; j++){
	cout << c;
    }
    cout << ' ';
  }
  cout << '\n';
}

void printshu(char *a, int s, int d){
  int i, j, k;
  for(j = 0; j < s; j++){
    for(i = 0; a[i] != '\0'; i++){
      int n = a[i] - '0';
      if(i != 0){
	cout << ' ';
      }
      if(shus[n][d] == 1){
	cout << '|';
      }else{
	cout << ' ';
      }
      for(k = 0; k < s; k++){
	cout << ' ';
      }
      if(shus[n][d+1] == 1){
	cout << '|';
      }else{
	cout << ' ';
      }
    }
    cout << '\n';
  }
}

int main(){
  int s;
  char a[10];
  int init = 1;
  while(cin >> s >> a){
    if(s == 0 && a[0] == '0'){
      break;
    }
    if(!init){
      cout << '\n';
    }else{
      init = 0;
    }
    printhen(a, s, 0);
    printshu(a, s, 0);
    printhen(a, s, 1);
    printshu(a, s, 2);
    printhen(a, s, 2);
  }
  return 0;
}
