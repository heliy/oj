#include<iostream>

using namespace std;

int capital[26];
int little[26];
int digital[10];

char line[10000];
char two[10000];

int find(char c){
  int i;
  for(i = 0; line[i] != '\0'; i++){
    if(line[i] == c){
      return i;
    }
  }
  return -1;
}

int main(){
  int n, ni;
  cin >> n;
  for(ni = 0; ni < n; ni++){
    cin >> line;
    int i, j = 0, index;
    for(i = 0; i < 26; i++){
      capital[i] = little[i] = 0;
    }
    for(i = 0; i < 10; i++){
      digital[i] = 0;
    }
    for(i = 0; line[i] != '\0'; i++){
      if(line[i] >= 'A' && line[i] <= 'Z'){
	capital[line[i]-'A']++;
      }
      if(line[i] >= 'a' && line[i] <= 'z'){
	little[line[i]-'a']++;
      }
      if(line[i] >= '0' && line[i] <= '9'){
	digital[line[i]-'0']++;
      }
    }
    for(i = 0; i < 26; i++){
      if(capital[i] == 2){
	two[j++] = 'A'+i;
	// cout << two[j-1] << endl;
      }
      if(little[i] == 2){
	two[j++] = 'a'+i;
	// cout << two[j-1] << endl;
      }
    }
    for(i = 0; i < 10; i++){
      if(digital[i] == 2){
	two[j++] = '0'+i;
	// cout << two[j-1] << endl;
      }
    }
    index = 10000;
    for(j--; j >= 0; j--){
      i = find(two[j]);
      // cout << two[j] << ": " << i << endl;
      if(i < index){
	index = i;
      }
    }
    cout << line[index] << endl;
  }
}
