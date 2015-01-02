#include<stdio.h>
#include<stdlib.h>

using namespace std;

int day_of_months[13][2] = {
  0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};

int intercalary(int year){
  if(year % 100 != 0 && year % 4 == 0 || year % 400 == 0){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int year, number;
  while(scanf("%d %d", &year, &number) != EOF){
    int is_leap = intercalary(year);
    int month, step;
    for(month = 1, step = 0; step < number; month++){
      step += day_of_months[month][is_leap];
    }
    month--;
    int day = number - (step - day_of_months[month][is_leap]);
    printf("%04d-", year);
    printf("%02d-", month);
    printf("%02d\n", day);
  }
  return 0;
}
