#include<stdio.h>
#include<string.h>

using namespace std;

char START[] = "START";
char END[] =  "END";
char EOI[] = "ENDOFINPUT";


char l[26] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
              'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
              'T', 'U' };

int main(){
  char line[210];
  while(true){
    fgets(line, 210, stdin);
    if(strstr(line, EOI) != NULL){
      break;
    }
    if(strstr(line, START) != NULL || strstr(line, END) != NULL){
      continue;
    }
    int i;
    for(i = 0; line[i] != '\0'; i++){
      if(line[i] >= 'A' && line[i] <= 'Z'){
	printf("%c", l[line[i] - 'A']);
      }else{
	printf("%c", line[i]);
      }
    }
  }
  return 0;
}
