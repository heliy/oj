#include<stdio.h>
#include<string.h>

using namespace std;

char bufs[100][101];

void strrev(char*, char*);

int main(){
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    int m, j, min_len = 101;
    char min_in[101], str[101], rev[101];
    scanf("%d", &m);
    for(j = 0; j < m; j++){
      scanf("%s", bufs[j]);
      if(strlen(bufs[j]) < min_len){
	min_len = strlen(bufs[j]);
	strcpy(min_in, bufs[j]);
      }
    }
    int loc, len;
    int max_len = 0;
    for(len = min_len-1; len > 0; len--){
      if(max_len > 0){
	break;
      }
      for(loc = 0; loc + len <= min_len; loc++){
	bool isTag = true;
	strncpy(str, min_in+loc, len);
	str[len] = '\0';
	strrev(str, rev);
	for(j = 0; j < m; j++){
	  if(strstr(bufs[j],str) == NULL && strstr(bufs[j], rev) == NULL){
	    isTag = false;
	    break;
	  }
	}
	if(isTag){
	  max_len = len;
	  break;
	}
      }
    }
    printf("%d\n", max_len);
  }
  return 0;
}

void strrev(char* str, char* rev){
  int i, j;
  for(i = 0; str[i] != '\0'; i++){
    ;
  }
  for(j = 0, i--; i >= 0; i--, j++){
    rev[j] = str[i];
  }
  rev[j] = '\0';
}
