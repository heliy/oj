#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct program{
  int begin;
  int end;
} Program;

int cmp(Program pro1, Program pro2){
  return pro1.end < pro2.end;
}

Program tracks[101];

int main(){
  int n, max, i, time;
  while(scanf("%d", &n) != EOF){
    if(n == 0){
      break;
    }
    for(i = 0; i < n; i++){
      scanf("%d %d", &tracks[i].begin, &tracks[i].end);
    }
    sort(tracks, tracks+n, cmp);
    max = 0;
    time = 0;
    for(i = 0; i < n; i++){
      if(time <= tracks[i].begin){
	time = tracks[i].end;
	max++;
      }
    }
    printf("%d\n", max);
  }
}
