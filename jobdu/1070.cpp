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
  int year, month, day;
  while(scanf("%d %d %d", &year, &month, &day) != EOF){
    int is_leap = intercalary(year);
    int number, step;
    for(number = 0, step = 1; step < month; step++){
      number += day_of_months[step][is_leap];
    }
    number += day;
    printf("%d\n", number);
  }
  return 0;
}
