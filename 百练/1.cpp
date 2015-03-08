#include<iostream>
#include<cstring>
#define N 200

using namespace std;

char word1[N+1], word2[N+1], shift[N*2+1];

int gcd(int a, int b){
  int max = (a>b)?a:b;
  int min = (a<b)?a:b;
  if(min == 0){
    return max;
  }
  return gcd(max%min, min);
}

int common(char *a, char*b, int len1, int len2){
  int i, j, k, com = 0;
  // cout << len1 << endl;
  for(i = 0; i < len1; i++){
    for(j = 0; j < N*2; j++){
      shift[j] = ' ';
    }
    for(k = i, j = 0; j < len2; j++, k++){
      shift[k] = b[j];
    }
    // cout << i << ":" << endl;
    // cout << shift << endl;
    // cout << a << endl;
    j = 0;
    k = i+len2;
    // cout << k << ", " << len1 << endl;
    k = (k>len1)?k:len1;
    // cout << k << endl;
    for(k--; k >= 0; k--){
      if(a[k] == shift[k]){
	// cout << k << ": " << a[k] << endl;
	j++;
      }
    }
  // cout << j << endl;
    if(j > com){
      com = j;
    }
  }
  return com;
}

int main(){
  word1[N] = word2[N] = shift[N*2] = '\0';
  while(cin >> word1){
    if(word1[0] == '-'){
      break;
    }
    cin >> word2;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i, j, k;
    for(i = len1; i < N; i++){
      word1[i] = ' ';
    }
    for(i = len2; i < N; i++){
      word2[i] = ' ';
    }
    int sa = common(word1, word2, len1, len2);
    int sb = common(word2, word1, len2, len1);
    sa = ((sa > sb)?sa:sb)*2;
    word1[len1] = '\0';
    word2[len2] = '\0';
    cout << "appx(" << word1 << "," << word2 << ") = ";
    if(sa == 0){
      cout << 0 << endl;
    }else if(sa == len1+len2){
      cout << 1 << endl;
    }else{
      int r = gcd(sa, len1+len2);
      cout << sa/r << "/" << (len1+len2)/r << endl;
    }
  }
}
