#include<iostream>

#define N 101

using namespace std;

boolean as[N], bs[N], cs[N];
boolean need[N];

int clear(boolean ss[], int l){
  int i, n = 0;
  for(i = 0; i < l-1; i++){
    if(ss[i] && ss[i+1]){
      n++;
      need[i] = true;
    }else{
      need[i] = false;
    }
  }
  if(ss[l-1] && ss[l-2]){
    n++;
    need[l-1] = true;
  }else{
    need[l-1] = false;
  }
  for(i = 0; i < l; i++){
    if(need[i]){
      ss[i] = false;
    }
  }
  return n;
}

int grade(int l){
  if(l == 0){
    return 0;
  }
  int i, j, n;
  n = clear(as, l);
  n += clear(bs, l);
  n += clear(cs, l);
  for(i = j = 0; i < l; i++){
    if(!as[i] && !bs[i] && !cs[i]){
      j++;
    }
    as[i-j] = as[i];
    bs[i-j] = as[i];
    cs[i-j] = cs[i];
  }
  return n+grade(l-n);
}

int main(){
  
}
