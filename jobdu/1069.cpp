#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct student{
  char no[100];
  char name[100];
  int age;
  char sex[5];
  bool operator < (const student & A) const{
    return strcmp(no, A.no) < 0;
  }
};

struct student students[1001];

int find(int n, char * f){
  int base = 0, top = n -1, mid = n/2;
  while(base <= top){
    int t = strcmp(f, students[mid].no); 
    if(t == 0){
      return mid;
    }else{
      if(t < 0){
        top = mid - 1;
      }else{
	base = mid + 1;
      }
      mid = (base + top) / 2;
    }
  }
  return -1;
}

int main(){
  int n, m;
  while(scanf("%d", &n) != EOF){
    int i, m, t;
    char f[100];
    for(i = 0; i < n; i++){
      scanf("%s %s %s %d", students[i].no, students[i].name, students[i].sex, &students[i].age);
    }
    sort(students, students+n);
    scanf("%d", &m);
    for(i = 0; i < m; i++){
      scanf("%s", f);
      t = find(n, f);
      if(t == -1){
        printf("No Answer!\n");
      }else{
        printf("%s %s %s %d\n", students[t].no, students[t].name, students[t].sex, students[t].age);
      }
    }
  }
}
