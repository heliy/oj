#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N 1001
#define MAXNAMELEN 101

using namespace std;

struct entry{
  char name[MAXNAMELEN];
  int age;
  int score;
};

bool cmp(entry a, entry b){
  if(a.score != b.score) return a.score < b.score;
  int tmp = strcmp(a.name, b.name);
  if(tmp != 0) return tmp < 0;
  else return a.age < b.age;
}

int main(){
  struct entry array[N];
  int n;
  while(scanf("%d", &n) != EOF){
    int i;
    for(i = 0; i < n; i++){
      scanf("%s %d %d", array[i].name, &array[i].age, &array[i].score);
    }
    sort(array, array+n, cmp);
    for(i = 0; i < n; i++){
      printf("%s %d %d\n", array[i].name, array[i].age, array[i].score);
    }
  }
  return 0;
}

