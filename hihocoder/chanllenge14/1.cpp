#include<cstdio>
#include<iostream>
#include<cstring>

#define MAX 1010
#define N 51

using namespace std;

int can[MAX];
int candidates[MAX];
int cless[N];
int clesseq[N];
int cmore[N];
int cmoreeq[N];

char inputs[N];

int main(){
  int less_n, lesseq_n, more_n, moreeq_n, candidates_n, count;
  int n, c, i, j;
  while(cin >> n){
    candidates_n = less_n = lesseq_n = more_n = moreeq_n = count = 0;
    for(i = 0; i < n; i++){
      cin >> inputs;
      cin >> inputs;
      cin >> c;
      if(inputs[0] == '='){
	candidates[candidates_n++] = c;
      }else if(inputs[0] == '<'){
	if(strlen(inputs) > 1){
	  clesseq[lesseq_n++] = c;
	}else{
	  cless[less_n++] = c;
	}
      }else{
	if(strlen(inputs) > 1){
	  cmoreeq[moreeq_n++] = c;
	}else{
	  cmore[more_n++] = c;
	}
      }
    }
    if(candidates_n == 0){
      candidates_n = MAX;
      for(i = 0; i < MAX; i++){
	candidates[i] = i-1;
	can[i] = 0;
      }
    }else{
      for(i = 0; i < candidates_n; i++){
	can[i] = 0;
      }
    }
    for(i = 0; i < less_n; i++){
      c = cless[i];
      for(j = 0; j < candidates_n; j++){
	if(candidates[j] < c){
	  can[j]++;
	  // cout << "less " << candidates[j] << endl;
	}
      }
    }
    for(i = 0; i < lesseq_n; i++){
      c = clesseq[i];
      for(j = 0; j < candidates_n; j++){
	if(candidates[j] <= c){
	  can[j]++;
	}
      }
    }
    for(i = 0; i < more_n; i++){
      c = cmore[i];
      for(j = 0; j < candidates_n; j++){
	if(candidates[j] > c){
	  can[j]++;
	}
      }
    }
    for(i = 0; i < moreeq_n; i++){
      c = cmoreeq[i];
      for(j = 0; j < candidates_n; j++){
	if(candidates[j] >= c){
	  can[j]++;
	}
      }
    }
    for(count = i = 0; i < candidates_n; i++){
      if(can[i] > count){
	count = can[i];
      }
    }
    if(candidates_n == MAX){
      cout << count << endl;
    }else{
      cout << (count+1) << endl;
    }
  }
}
