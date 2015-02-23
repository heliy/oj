#include<stdio.h>
#include<algorithm>

using namespace std;

char line1[101], line2[101];

int count1[26], count2[26];

void take(char* line, int* count){
  int i;
  for(i = 0; i < 26; i++){
    count[i] = 0;
  }

  for(i = 0; line[i] != '\0' && line[i] != '\n'; i++){
    count[line[i] - 'A']++;
  }
}

int is_equal(int* count1, int* count2){
  int i;
  for(i = 0; i < 26; i++){
    if(count1[i] != count2[i]){
      return 0;
    }
  }
  return 1;
}

int main(){
  scanf("%s", line1);
  scanf("%s", line2);
  take(line1, count1);
  take(line2, count2);
  sort(count1, count1+26);
  sort(count2, count2+26);
  if(is_equal(count1, count2)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}
