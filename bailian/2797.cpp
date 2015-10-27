#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define MAX(A, B) (A)>(B)?(A):(B)

using namespace std;

int common(string str1, string str2){
  int i;
  for(i = 0; i < str1.length() && i < str2.length(); i++){
    if(str1[i] != str2[i]){
      return i;
    }
  }
  return i;
}


int main(){
  vector<string> words;
  string temp;
  int i, j, l, k, n = 0;
  while(cin >> temp){
    words.push_back(temp);
    n++;
  }

  for(i = 0; i < n; i++){
    for(l = 0; l < words[i].length(); l++){
      int all = 1;
      for(j = 0; j < n; j++){
	if( j == i){
	  continue;
	}
	int is_match = 1;
	for(k = 0; k < l; k++){
	  if(words[i][k] != words[j][k]){
	    is_match = 0;
	    break;
	  }
	}
	if(is_match == 1){
	  all = 0;
	  continue;
	}
      }
      if(all == 1){
	break;
      }
    }
    cout << words[i] << ' ' << words[i].substr(0, l) << '\n';
  }
  return 0;
}
