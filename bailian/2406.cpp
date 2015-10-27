#include<cstdio>
#include<iostream>
#include<cstring>

char line[1000000];

int main(){
  while(scanf("%s", line) != EOF && line[0] != '.'){
    int len = strlen(line), n, sub, i, j;
    for(sub = 1; sub <= len; sub++){
      if(len%sub != 0){
	continue;
      }
      bool issub = true;
      n = len/sub;
      for(i = 1; i < n; i++){
	for(j = 0; j < sub; j++){
	  if(line[i*sub+j] != line[j]){
	    issub = false;
	    break;
	  }
	}
	if(!issub){
	  break;
	}
      }
      if(issub){
	printf("%d\n", n);
	break;
      }
    }
  }
}
