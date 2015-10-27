#include<iostream>
#include<cstdio>
#include<cmath>
#define N 32780

using namespace std;

int ps[N];
int es[N];
int primes[N];
int set_primes(){
  int i, j, num = 0;
  for(i = 2; i < N; i++){
    ps[i] = 1;
  }
  for(i = 2; i < N; i++){
    if(ps[i]){
      for(j = i*2; j < N; j *= i){
	ps[j] = 0;
      }
      primes[num++] = i;
    }
  }
  return num;
}

char line[N];

int getnum(char* a, int end){
  int i, j, num = 0;
  for(i = end, j = 1; i >= 0 && a[i] != ' '; i--, j *= 10){
    num += (a[i]-'0')*j;
    // cout << i << ", " << a[i] << ": " << num;
  }
  return num;
}

int main(){
  int total = set_primes();
  while(fgets(line, N, stdin) != NULL && line[0] != '0'){
    int i, j, num = 1, prev, thisnum, p, e;
    for(i = j = 0; line[i] != '\0'; i++){
      if(line[i] == ' ' || line[i+1] == '\0'){
	  thisnum = getnum(line, i-1);
	if(j == 1){
	  num *= pow(prev, thisnum);
	  j = 0;
	}else{
	  j = 1;
	  prev = thisnum;
	}
      }
    }
    num--;
    for(i = j = 0; i < total && num >= primes[i]; i++){
      if(num%primes[i] == 0){
	p = primes[i];
	e = 0;
	while(num%p == 0){
	  e++;
	  num /= p;
	}
	ps[j] = p;
	es[j] = e;
	j++;
      }
    }
    for(j--; j >= 0; j--){
      cout << ps[j] << ' ' << es[j];
      if(j != 0){
	cout << " ";
      }
    }
    cout << endl;
  }
}
