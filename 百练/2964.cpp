#include<stdio.h>

using namespace std;

char days[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int monthsday[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int n){
  if(n%400 == 0 || (n%100 != 0 && n%4 == 0)){
    return 1;
  }else{
    return 0;
  }
}

int thisyear(int y){
  if(isleap(y)){
    return 366;
  }else{
    return 365;
  }
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF && n != -1){
    int s = (n+6)%7;
    int year = 2000;
    while(n >= thisyear(year)){
      n -= thisyear(year);
      year++;
    }
    int month = 1;
    while(n >= monthsday[isleap(year)][month]){
      n -= monthsday[isleap(year)][month];
      month++;
    }
    int day = n+1;
    printf("%04d-%02d-%02d %s\n", year, month, day, days[s]);
  }
  return 0;
}
