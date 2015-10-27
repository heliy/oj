#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct{
  char from[101];
  char to[101];
} word;

int mystrcmp(char * str1, char * str2){
  int i;
  for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
    if(str1[i] != str2[i]){
      return str1[i] - str2[i];
    }
  }
  if(str1[i] != '\0'){
    return 1;
  }
  if(str2[i] != '\0'){
    return -1;
  }
  return 0;
}

int wordcmp(word w1, word w2){
  return mystrcmp(w1.from, w2.from);
}

word dict[100001];

int find(int len, char* get){
  int up, low, mid;
  up = len;
  low = 1;
  while(up >= low){
    mid = (up + low)/2;
    int cmp = mystrcmp(dict[mid].from, get);
    printf("%d, %d, %d, %d, %s, %s\n", up, low, mid, cmp, dict[mid].from, get);
    if(cmp == 0){
      return mid;
    }else if(cmp < 0){
      up = mid -1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}

int main(){
  int i, j, k = 0;
  char line[25];
  while(true){
    fgets(line, 25, stdin);
    if(line[0] == '\0' || line[0] == '\n'){
      break;
    }
    k++;
    for(i = 0; line[i] != ' '; i++)
      ;
    strncpy(dict[k].to, line, i);
    dict[k].to[i++] = '\0';
    for(j = 0; line[j + i] != '\0' && line[j + i] != '\n'; j++)
      ;
    strncpy(dict[k].from, line+i, j);
    dict[k].from[j] = '\0';
    puts(dict[k].from);
  }
  sort(dict+1, dict+(k+1), wordcmp);

  for(i = 1; i <= k; i++){
    printf("%d: %s\n", i, dict[i].from);
  }
  while(scanf("%s", line) != EOF){
    int f = find(k, line);
    if(f < 0){
      printf("eh\n");
    }else{
      printf("%s\n", dict[f].to);
    }
  }
  return 0;
}
