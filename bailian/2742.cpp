#include<stdio.h>

using namespace std;

int main(){
  char line[1005];
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    fgets(line, 1005, stdin);
    fgets(line, 1005, stdin);
    int count[26];
    int j;
    for(j = 0; j < 26; j++){
      count[j] = 0;
    }
    for(j = 0; line[j] != '\n' && line[j] != '\0'; j++){
      count[line[j] - 'a'] ++;
    }
    int max = 0, max_j = 0;
    for(j = 0; j < 26; j++){
      if(count[j] > max){
	max = count[j];
	max_j = j;
      }
    }
    printf("%c %d\n", 'a'+max_j, max);
  }
  return 0;
}
