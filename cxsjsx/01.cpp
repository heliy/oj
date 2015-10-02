#include<cstdio>
#include<iostream>

#define PART 1000

using namespace std;

int dits[PART*2];
int pows[PART*2];
int multi[PART*2];
int temp[PART*2];

int factor[PART];
int factorlen;

void clear(int* array, int len){
  int i;
  for(i = 0; i < len; i++){
    array[i] = 0;
  }
}

void copy(int* from, int* to, int len){
  int i;
  for(i = 0; i< len; i++){
    to[i] = from[i];
  }
}

void factortobits(int n){
  factorlen = 0;
  while(n != 0){
    factor[factorlen++] = n%10;
    n /= 10;
  }
}

void todits(double d){
  int i = PART, n = (int)d;
  while(n != 0){
    dits[i--] = n%10;
    n /= 10;
  }
  d -= (int)d;
  i = PART + 1;
  while(d > 0.0){
    dits[i] = (int)d*10;
    d = d*10 - dits[i++];
  }
}

void multi(int n){
  int m, plus = 0;
  for(i = PART*2-1; i >= 0; i--){
    m = pows[i]*n;
    multi[i] = (m+plus)%10;
    plus = (m+plus)/10;
  }
}

void leftturn(int off){
  int i;
  for(i = 0; i+off < PART*2; i++){
    multi[i] = multi[i+off];
  }
  for(i < PART*2; i++){
    multi[i] = 0;
  }
}

void rightturn(int off){
  int i;
  for(i = off; i < PART*2; i++){
    multi[i] = multi[i-off];
  }
  for(i = 0; i < off; i++){
    multi[i] = 0;
  }
}

void pow2(){
  clear(temp, PART*2);
  clear(multi, PART*2);

  int i;
  for(i = 0; i <= PART; i++){
    if(pows[i] != 0){
      multi(pows[i]);
      leftturn(PART-i);
    }
  }
  for(; i < PART*2; i++){
    if(pows[i] != 0){
      multi(pows[i]);
      rightturn(i-PART);
    }
  }
}

void merge(int* from, int* to){
  
}

void print(int* array){
  
}

int main(){
  double in;
  int m, n, i;
  while(cin >> in >> m){
    clear(dits, PART*2);
    clear(pows, PART*2);
    clear(factor, PART);
    todits(in);
    copy(dits, pows);
    factortobits(m);
    if(factor[0] == 0){
      clear(dits, PART*2);
    }
    for(i = 1; i < factorlen; i++){
      pow2();
      if(factor[i]){
	merge(pows, dits);
      }
    }
    print(dits);
  }
}
