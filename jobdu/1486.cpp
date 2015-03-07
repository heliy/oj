#include<iostream>
#define N 1010
#define K 102
using namespace std;

int Left[K][N/2];
int Right[K][N/2];
int pis[K];
char res[K];

int n, k;

bool isin(int* a, int t, int pi){
  int i;
  for(i = 0; i < pi; i++){
    if(a[i] == t){
      return true;
    }
  }
  return false;
}

bool islight(int tar){
  int i;
  for(i = 0; i < k; i++){
    if(isin(Left[i], tar, pis[i])){
      if(res[i] != '<'){
	return false;
      }
    }else if(isin(Right[i], tar, pis[i])){
      if(res[i] != '>'){
	return false;
      }
    }else{
      if(res[i] != '='){
	return false;
      }
    }
  }
  return true;
}

bool isheavy(int tar){
  int i;
  for(i = 0; i < k; i++){
    if(isin(Left[i], tar, pis[i])){
      if(res[i] != '>'){
	return false;
      }
    }else if(isin(Right[i], tar, pis[i])){
      if(res[i] != '<'){
	return false;
      }
    }else{
      if(res[i] != '='){
	return false;
      }
    }
  }
  return true;
}

int main(){
  int i, j;
  while(cin >> n >> k){
    for(i = 0; i < k; i++){
      cin >> pis[i];
      for(j = 0; j < pis[i]; j++){
	cin >> Left[i][j];
      }
      for(j = 0; j < pis[i]; j++){
	cin >> Right[i][j];
      }
      res[i] = ' ';
      while(res[i] != '<' && res[i] != '=' && res[i] != '>'){
	cin >> res[i];
      }
    }
    int sd = -1;
    for(i = 1; i <= n; i++){
      if(islight(i) || isheavy(i)){
	cout << i << endl;
	sd = 1;
	//	break;
      }
    }

    if(sd < 0){
      cout << 0 << endl;
    }
  }
}
