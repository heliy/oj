#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char months[13][20] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int getmonth(char* m){
  int i;
  for(i = 1; i < 13; i++){
    if(strcmp(m, months[i]) == 0){
      return i;
    }
  }
  return -1;
}

bool isleap(int year){
  return (year%400 == 0 || (year%4 == 0 && year%100 != 0));
}

bool before(int m, int d){
  return ((m == 1) || ((m == 2) && (d <= 29)));
}

bool after(int m, int d){
  return ((m >= 3) || (m == 2 && d == 29));
}

int begin(int y, int m, int d){
  if(isleap(y) && before(m, d)){
    return 1;
  }else{
    return 0;
  }
}

int end(int y, int m, int d){
  if(isleap(y) && after(m, d)){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int t, ti, y1, m1, d1, y2, m2, d2, c, i;
  char month[20];
  char line[100];
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    scanf("%s %d, %d", month, &d1, &y1);
    m1 = getmonth(month);
    scanf("%s %d, %d", month, &d2, &y2);
    m2 = getmonth(month);
    c = 0;
    if(y2 == y1){
      if(isleap(y1) && before(m1, d1) && after(m2, d2)){
	c = 1;
      }
    }else{
      c = begin(y1, m1, d1);
      for(i = y1+1; i < y2; i++){
	if(isleap(i)){
	  c++;
	}
      }
      c += end(y2, m2, d2);      
    }
    //  if((y2 - y1) < 8){
    //   c = begin(y1, m1, d1);
    //   for(i = y1+1; i < y2; i++){
    // 	if(isleap(i)){
    // 	  c++;
    // 	}
    //   }
    //   c += end(y2, m2, d2);
    // }else{
    //   c = begin(y1, m1, d1);
    //   for(i = y1+1; i)
    // }
    cout << "Case #" << ti << ": " << c << endl;
  }
}
