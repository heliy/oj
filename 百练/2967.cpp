#include<stdio.h>

using namespace std;

int days[13] = {
  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};


int isleap(int y){
  if(y%400 == 0 || (y%100 != 0 && y%4 == 0)){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    int hour, minute, second, day, month, year;
    scanf("%d:%d:%d %d.%d.%d", &hour, &minute, &second, &day, &month, &year);
    int k, d = 0;
    for(k = 2000; k < year; k++){
      if(isleap(k)){
	d += 366;
      }else{
	d += 365;
      }
    }
    for(k = 1; k < month; k++){
      d += days[k];
    }
    d += day;
    year = d / (1000);
    d %= 1000;
    month = d / 100 + 1;
    day = d % 100;

    int sc = hour*60*60 + minute*60 + second;
    sc = (int)(100000*(sc/(float)24*60*60));
    hour = sc/10000;
    sc %= 10000;
    minute = sc/100;
    second = sc % 100;
    printf("%d:%d:%d %d.%d.%d\n", hour, minute, second, day, month, year);
  }
  return 0;
}
