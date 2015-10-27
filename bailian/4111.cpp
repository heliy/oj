#include<iostream>
#define N 1000

using namespace std;

char A16[N], B16[N];
int A2[N*4], B2[N*4];

void tobina(int* a, char c){
  int v = ('a' <= c && c <= 'f')?(c-'a'+10):(c-'0');
  int i;
  for(i = 3; i >= 0; i--){
    a[i] = v%2;
    v /= 2;
  }
}

int block(int *a2, char* a16){
  int i = 2, j = 0;
  for(; a16[i] != '\0'; i++){
    tobina(a2+j, a16[i]);
    j += 4;
  }
  return j;
}

int count(int* a, int len){
  int blocks = a[0];
  int i;
  for(i = 1; i < len; i++){
    if(a[i] == 1 && a[i-1] == 0){
      blocks++;
    }
  }
  return blocks;
}

int main(){
  int n, ni;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    cin >> A16 >> B16;
    int lenA = block(A2, A16);
    int lenB = block(B2, B16);
    int d = count(A2, lenA) - count(B2, lenB);
    if(d > 0){
      cout << "Alice" << endl;
    }else if(d < 0){
      cout << "Bob" << endl;
    }else{
      cout << "Tie" << endl;
    }
  }
}
