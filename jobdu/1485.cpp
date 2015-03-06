#include<iostream>
#define N 1000

using namespace std;

char line[N];
char ccato[3][N];
int icato[3][N];
int ks[3];
int kn[3];

int main(){
  while(cin >> ks[0] >> ks[1] >> ks[2]){
    if(ks[0] == 0 && ks[1] == 0 && ks[2] == 0){
      break;
    }
    cin >> line;
    char c;
    int i, j, tag;
    kn[0] = kn[1] = kn[2] = 0;
    for(i = 0; line[i] != '\0'; i++){
      if(line[i] == '_' || line[i] >= 's'){
	tag = 2;
      }else if(line[i] <= 'i'){
	tag = 0;
      }else{
	tag = 1;
      }
      ccato[tag][kn[tag]] = line[i];
      icato[tag][kn[tag]] = i;
      kn[tag]++;
    }
    for(tag = 0; tag < 3; tag++){
      if(kn[tag] == 0){
	continue;
      }
      ks[tag] %= kn[tag];
      i = 0;
      for(j = 0; j < ks[tag]; j++){
	line[icato[tag][i++]] = ccato[tag][kn[tag]-ks[tag]+j];
      }
      for(j = 0; j < kn[tag] - ks[tag]; j++){
	line[icato[tag][i++]] = ccato[tag][j];
      }
    }
    cout << line << endl;
  }
}
