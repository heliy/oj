#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define N 100001

using namespace std;

struct entry{
  char number[7];
  char name[9];
  int mark;
};

bool cmp1(entry a, entry b){
  return strcmp(a.number, b.number) < 0;
}

bool cmp2(entry a, entry b){
  int tmp = strcmp(a.name, b.name);
  if(tmp != 0 ) return tmp <= 0;
  else{
    return cmp1(a, b);
  }
}

bool cmp3(entry a, entry b){
  if(a.mark != b.mark) return a.mark <= b.mark;
  else return cmp1(a, b);
}

int main(){
  int case_number = 0, n, cmp_number;
  struct entry array[N];
  while(scanf("%d %d", &n, &cmp_number) != EOF){
    if(n == 0){
      break;
    }
    case_number++;
    int i;
    for(i = 0; i < n; i++){
      scanf("%s %s %d", array[i].number, array[i].name, &array[i].mark);
    }
    if(cmp_number == 1){
      sort(array, array+n, cmp1);
    }else if(cmp_number == 2){
      sort(array, array+n, cmp2);
    }else{
      sort(array, array+n, cmp3);
    }
    printf("Case %d:\n", case_number);
    for(i = 0; i < n; i++){
      printf("%s %s %d\n", array[i].number, array[i].name, array[i].mark);
    }
  }
  return 0;
}
