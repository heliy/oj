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

bool isleap(long year){
  return (year%400 == 0 || (year%4 == 0 && year%100 != 0));
}

bool before(int m, int d){
  return ((m == 1) || ((m == 2) && (d <= 29)));
}

bool after(int m, int d){
  return ((m >= 3) || (m == 2 && d == 29));
}

int begin(long y, int m, int d){
  if(isleap(y) && before(m, d)){
    return 1;
  }else{
    return 0;
  }
}

int end(long y, int m, int d){
  if(isleap(y) && after(m, d)){
    return 1;
  }else{
    return 0;
  }
}

long between(long begin, long end){
  // cout << begin << ", " << end << endl;
  long c = (end-begin)/4+1;
  // cout << c << endl;
  if(begin/100 != end/100){ // 跨世纪
    long i, j;
    c -= (end/100 - begin/100); // -所有被100整除的
    // cout << c << endl;
    for(i = begin/100+1; i < end/100; i++){
      if(i%4 == 0){
	break;
      }
    }
    for(j = end/100; j > begin/100; j--){
      if(j%4 == 0){
	break;
      }
    }
    // cout << i << ", " << j << endl;
    if(j < i){
      return c;
    }
    c += (j-i)/4+1;    // +400的
  }
  return c;
}

int main(){
  int t, ti, m1, d1, m2, d2;
  long y1, y2, c, i, j;
  char month[20];
  char line[100];
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    scanf("%s %d, %ld", month, &d1, &y1);
    m1 = getmonth(month);
    scanf("%s %d, %ld", month, &d2, &y2);
    m2 = getmonth(month);
    c = 0;
    if(y2 == y1){
      if(isleap(y1) && before(m1, d1) && after(m2, d2)){
	c = 1;
      }
    }else if((y2 - y1) < 9){
      c = begin(y1, m1, d1);
      for(i = y1+1; i < y2; i++){
    	if(isleap(i)){
    	  c++;
    	}
      }
      c += end(y2, m2, d2);
    }else{
      c = begin(y1, m1, d1);
      for(i = y1+1; i < y2; i++){
	if(isleap(i)){
	  break;
	}
      }
      // cout << c << endl;
      c += end(y2, m2, d2);
      for(j = y2-1; j > y1; j--){
	if(isleap(j)){
	  break;
	}
      }
      // cout << c << endl;
      c += between(i, j);
    }
    cout << "Case #" << ti << ": " << c << endl;
  }
}
