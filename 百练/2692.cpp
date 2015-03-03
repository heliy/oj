#include<stdio.h>
#include<string.h>
using namespace std;

/*测试数据均过 无法AC*/

char sc[3][3][10];

int isin(char c, char* line){
  int i;
  for(i = 0; line[i] != '\0'; i++){
    if(line[i] == c){
      return 1;
    }
  }
  return 0;
}

int islight(char x){
  int i;
  for(i = 0; i < 3; i++){
    switch(sc[i][2][0]){
    case 'u':
      if(strchr(sc[i][1], x) == NULL){
	return 0;
      }
      break;
    case 'e':
      if(strchr(sc[i][0], x) != NULL || strchr(sc[i][1], x) != NULL){
	return 0;
      }
      break;
    case 'd':
      if(strchr(sc[i][0], x) == NULL){
	return 0;
      }
      break;
    }
  }
  return 1;
}

int isheavy(char x){
  int i;
  for(i = 0; i < 3; i++){
    switch(sc[i][2][0]){
    case 'u':
      if(strchr(sc[i][0], x) == NULL){
	return 0;
      }
      break;
    case 'e':
      if(strchr(sc[i][0], x) != NULL || strchr(sc[i][1], x) != NULL){
	return 0;
      }
      break;
    case 'd':
      if(strchr(sc[i][1], x) == NULL){
	return 0;
      }
      break;
    }
  }
  return 1;
}

int main(){
  int n, ni;
  scanf("%d", &n);
  for(ni = 0; ni < n; ni++){
    int i, j, k = -1;
    for(i = 0; i < 3; i++){
      scanf("%s %s %s", sc[i][0], sc[i][1], sc[i][2]);
    }
    for(i = 0; i < 11; i++){
      if(islight('A'+i)){
	printf("%c is the counterfeit coin and it is light.\n", 'A'+i);
      }
      if(isheavy('A'+i)){
	printf("%c is the counterfeit coin and it is heavy.\n", 'A'+i);
      }
    }
  }
}
