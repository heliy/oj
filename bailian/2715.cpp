#include<stdio.h>

using namespace std;

int main(){
  int n, i, j;
  char line[100];
  char name[20];
  scanf("%d", &n);
  int sum, max;
  sum = max = 0;
  fgets(line, 100, stdin);
  for(i = 0; i < n; i++){
    fgets(line, 100, stdin);
    for(j = 0; line[j] != ' '; j++){
      ;
    }
    j++;
    int g1, g2;
    if(line[j+1] == ' '){
      g1 = line[j] - '0';
      j += 2;
    }else if(line[j+2] == ' '){
      g1 = (line[j] - '0')*10 + line[j+1] - '0';
      j += 3;
    }else{
      g1 = 100;
      j += 4;
    }
    if(line[j+1] == ' '){
      g2 = line[j] - '0';
      j += 2;
    }else if(line[j+2] == ' '){
      g2 = (line[j] - '0')*10 + line[j+1] - '0';
      j += 3;
    }else{
      g2 = 100;
      j += 4;
    }
    int is_offical, is_western, papers; 
    if(line[j] == 'Y'){
      is_offical = 1;
    }else{
      is_offical = 0;
    }
    j += 2;
    if(line[j] == 'Y'){
      is_western = 1;
    }else{
      is_western = 0;
    }
    j += 2;
    if(line[j+1] != '0'){
      papers = line[j] - '0';
    }else{
      papers = 10;
    }
    int thissum = 0;
    if(g1 > 80 && papers > 0){
      thissum += 8000;
    }
    if(g1 > 85 && g2 > 80){
      thissum += 4000;
    }
    if(g1 > 90){
      thissum += 2000;
    }
    if(g1 > 85 && is_western){
      thissum += 1000;
    }
    if(g2 > 80 && is_offical){
      thissum += 850;
    }
    sum += thissum;
    if(thissum > max){
      max = thissum;
      for(j = 0; line[j] != ' '; j++){
	name[j] = line[j];
      }
      name[j] = '\0';
    }
  }
  printf("%s\n%d\n%d\n", name, max, sum);
}
