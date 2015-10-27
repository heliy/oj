#include<stdio.h>
#include<string.h>

using namespace std;

char haab_months_name[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

char holly_days_name[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int haab_month(char *name){
  int i;
  for(i = 0; i < 19; i++){
    if(strcmp(name, haab_months_name[i]) == 0){
      return i;
    }
  }
  return -1;
}

int haab_count(int y, int m, int d){
  return y*365+20*m+d;
}

int main(){
  int i, n;
  scanf("%d", &n);
  printf("%d\n", n);
  for(i = 0; i < n; i++){
    int hd, hm, hy;
    char hms[10];
    scanf("%d. %s %d", &hd, hms, &hy);
    hm = haab_month(hms);
    int count = haab_count(hy, hm, hd);
    int td, tm, ty;
    ty = count/260;
    count = count%260;
    tm = count%13 + 1;
    td = count%20;
    printf("%d %s %d\n", tm, holly_days_name[td], ty);
  }
  return 0;
}


