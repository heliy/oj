#include<stdio.h>

using namespace std;

int day_of_months[13][2] = {
  0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};

int calary_year = 366;
int non_calary_year = 365;

struct date{
  int year;
  int month;
  int day;
};

int cmp(struct date d1,struct date d2){
  if(d1.year != d2.year){
    return d1.year < d2.year;
  }else if(d1.month != d2.month){
    return d1.month < d2.month;
  }else{
    return d1.day < d2.day;
  }
}

int intercalary(int year){
  if(year % 100 != 0 && year % 4 == 0 || year % 400 == 0){
    return 1;
  }else{
    return 0;
  }
}

int divide(struct date mae,struct date ato){
  if(mae.year == ato.year && mae.month == ato.month){
    return ato.day - mae.day + 1;
  }else if(mae.year == ato.year){
    int day = day_of_months[mae.month][intercalary(mae.year)] - mae.day + 1;
    int i;
    for(i = mae.month + 1;i != ato.month; i++){
      day += day_of_months[i][intercalary(mae.year)];
    }
    return day + ato.day;
  }else{
    int day = day_of_months[mae.month][intercalary(mae.year)] - mae.day + 1;
    int i;
    for(i = mae.month + 1; i != 13; i++){
      day += day_of_months[i][intercalary(mae.year)];
    }
    for(i = mae.year + 1; i != ato.year; i++){
      if(intercalary(i)){
	day += calary_year;
      }else{
	day += non_calary_year;
      }
    }
    for(i = 1; i != ato.month; i++){
      day += day_of_months[i][intercalary(ato.year)];
    }
    day += ato.day;
    return day;
  }
}

int main(){
  struct date d1,d2;
  while(scanf("%4d%2d%2d", &d1.year, &d1.month, &d1.day) != EOF){
    scanf("%4d%2d%2d", &d2.year, &d2.month, &d2.day);
    int d;
    if(cmp(d1, d2)){
      d = divide(d1, d2);
    }else{
      d = divide(d2, d1);
    }
    printf("%d\n", d);
  }
}
