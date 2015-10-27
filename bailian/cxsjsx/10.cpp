#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100

using namespace std;

int oneNum[26];
int twoNum[26];

char one[N];
char two[N];

void setMap(char* array, int* num){
  int i, n = strlen(array);
  for(i = 0; i < 26; i++){
    num[i] = 0;
  }
  for(i = 0; i < n; i++){
    num[array[i]-'A']++;
  }
}

bool issame(int *a, int* b){
  int i;
  for(i = 0; i < 26; i++){
    // cout << a[i] << ", " << b[i] << endl;
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

int main(){
  cin >>  one >> two;
  if(strlen(one) != strlen(two)){
    cout << "NO" << endl;
    return 0;
  }
  // cout << strlen(one) << ", " << strlen(two) << endl;
  setMap(one, oneNum);
  setMap(two, twoNum);
  sort(oneNum, oneNum+26);
  sort(twoNum, twoNum+26);
  if(issame(oneNum, twoNum)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
