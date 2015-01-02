#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    return d1.year <= d2.year;
  }else if(d1.month != d2.month){
    return d1.month <= d2.month;
  }else{
    return d1.day <= d2.day;
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
    return ato.day - mae.day;
  }else if(mae.year == ato.year){
    int day = day_of_months[mae.month][intercalary(mae.year)] - mae.day;
    int i;
    for(i = mae.month + 1;i != ato.month; i++){
      day += day_of_months[i][intercalary(mae.year)];
    }
    return day + ato.day;
  }else{
    int day = day_of_months[mae.month][intercalary(mae.year)] - mae.day;
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

char weeks[8][20] = {
  "","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"
};

int match(char * string){
  char months[13][20] = {
    "","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };
  int i;
  for(i = 1; i < 13; i++){
    if(strcmp(months[i], string) == 0){
      return i;
    }
  }
  return -1;
}

int main(){
  struct date now;
  now.year = 2015;
  now.month = 1;
  now.day = 5;
  int day, year;
  char string[20];
  while(scanf("%d %s %d", &day, string, &year) != EOF){
    int month = match(string);
    struct date another;
    another.year = year;
    another.month = month;
    another.day = day;
    int d;
    if(cmp(now, another)){ // now <= another
      d = (divide(now, another) % 7) + 1;
    }else{                // now > another
      d = divide(another, now);
      d = 8 - (d % 7);
    }
    printf("%s\n", weeks[d]);
  }
}
