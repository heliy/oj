#include<iostream>
#include<cstring>

using namespace std;

char prev[27], midd[27], post[27];

void build(int previ, int prevj, int middi, int middj, int posti){
  if(previ > prevj || middi > middj || posti < 0){
    return;
  }
  post[posti] = prev[previ];
  if(previ == prevj || middi == middj){
    return;
  }
  int left, root;
  for(root = middi-1, left = -1; prev[previ] != midd[root]; root++, left++)
    ;
  build(previ+1, previ+left, middi, root-1, posti-(middj-root)-1);
  build(previ+left+1, prevj, root+1, middj, posti-1);
}

int main(){
  int i, len;
  while(cin >> prev >> midd){
    len = strlen(prev);
    build(0, len-1, 0, len-1, len-1);
    for(i = 0; i < len; i++){
      cout << post[i];
    }
    cout << endl;
  }
}
