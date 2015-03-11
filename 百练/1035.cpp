#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct word{
  char w[15];
  int len;
  int index;
};

struct word dict[10001];
char line[20], back[20];


int lens[17];

bool cmp1(struct word w1, struct word w2){
  return (w1.len < w2.len);
}

bool cmp2(struct word w1, struct word w2){
  return (w1.index < w2.index);
}

struct word ss[10000];
int ss_len = 0;

void tolens(int n){
  int i, j, l;
  lens[0] = 0;
  for(i = 0, j = 0; i < n; i++){
    l = dict[i].len;
    if( l > j){
      lens[l] = i;
      j = l;
    }
  }
  for(i = 1; i < l; i++){
    if(lens[i] == 0){
      lens[i] = lens[i-1];
    }
  }
}

bool find(int len, int n){
  int i = lens[len];
  while(i < n && dict[i].len <= len){
    if(strcmp(dict[i].w, line) == 0){
      return true;
    }
    i++;
  }
  return false;
}

bool istype1(char *a, char*b, int alen){
  // len(a) == len(b)+1
  int i, j;
  for(i = 0; i < alen; i++){
    for(j = 0; j < alen; j++){
      if(i == j){
	continue;
      }else if(i > j){
	back[j] = a[j];
      }else{
	back[j-1] = a[j];
      }
    }
    back[alen-1] = '\0';
    if(strcmp(back, b) == 0){
      return true;
    }
  }
  return false;
}

bool istype2(char*a, int len){
  int i, c;
  for(i = c = 0; i < len; i++){
    if(line[i] != a[i]){
      c++;
    }
  }
  if(c == 1){
    return true;
  }else{
    return false;
  }
}

int main(){
  int n = 0;
  while(cin >> dict[n].w){
    if(dict[n].w[0] == '#'){
      break;
    }
    dict[n].len = strlen(dict[n].w);
    dict[n].index = n;
    n++;
  }
  sort(dict, dict+n, cmp1);
  tolens(n);

  while(true){
    cin >> line;
    if(line[0] == '#'){
      break;
    }
    int l = strlen(line), i, j;
    cout << line;
    if(find(l, n)){
      cout << " is correct" << endl;
    }else{
      cout << ":";
      for(i = lens[l-1]; i <= n && dict[i].len <= (l+1); i++){
  	bool b= false;
  	if(l == dict[i].len && istype2(dict[i].w, l)){
  	  b = true;
  	}else if(l == dict[i].len+1 && istype1(line, dict[i].w, l)){
  	  b = true;
  	}else if(l+1 == dict[i].len && istype1(dict[i].w, line, l+1)){
  	  b = true;
  	}
  	if(b){
	  for(j = 0; j < dict[i].len; j++){
	    ss[ss_len].w[j] = dict[i].w[j];
	  }
	  ss[ss_len].w[j] = '\0';
	  ss[ss_len++].index = dict[i].index;
  	}
      }
      sort(ss, ss+ss_len, cmp2);
      for(j = 0; j < ss_len; j++){
	cout << " " << ss[j].w;
      }
      ss_len = 0;
      cout << endl;
    }
  }
  return 0;
}

