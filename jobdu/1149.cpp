#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
  string s;
  while(cin >> s){
    map<string, int> count;
    int i, j, l = s.size();
    for(i = 1; i < l; i++){
      for(j = 0; j < l; j++){
	string temp(s, j, i);
	count[temp]++;
      }
    }
    map<string, int>:: iterator it = count.begin();
    while(it != count.end()){
      if(it->second > 1){
	cout << it->first << " " << it->second << endl;
      }
      it++;
    }
  }
}
