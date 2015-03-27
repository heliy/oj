#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


/*WA*/

char names[200][20];
char line[4000];

int ds[3];

char onedits[10][20] = {
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

char twodits1[9][20] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};

char twodits2[10][20] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred",
};

int find(char *a, char array[][20], int n){
  int i;
  for(i = 0; i < n; i++){
    if(strcmp(a, array[i]) == 0){
      return i;
    }
  }
  return -1;
}


int main(){
  while(fgets(line, 4000, stdin) != NULL){
    if(line[0] == ' '){
      break;
    }
    ds[0] = ds[1] = ds[2] = 0;
    int i, j, n;
    for(n = j = i = 0; true; i++, j++){
      if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0'){
	names[n][j] = '\0';
	j = -1;
	n++;
	if(line[i] != ' '){
	  break;
	}
      }else{
	names[n][j] = line[i];
      }
    }
    long long num = 0, flag = 0, temp = 0, t;
    for(i = 0; i < n; i++){
      if(strcmp(names[i], "negative") == 0){
        flag = 1;
      }else if((t = find(names[i], twodits1, 9)) && t > 0){
	temp += (11+t);
      }else if((t = find(names[i], twodits2, 10)) && t > 0){
	if(t == 9){
	  temp *= 100;
	}else{
	  temp += (10*t+10);
	}
      }else if((t = find(names[i], onedits, 10)) && t > 0){
	temp += (t);
      }else{
	if(strcmp(names[i], "thousand") == 0){
	  ds[1] = temp;
	}else{
	  ds[0] = temp;
	}
	temp = 0;
      }
      // cout << ds[0]<<","<<ds[1]<<","<<ds[2] << ":" << temp << endl;

    }
    ds[2] = temp;
    if(flag){
      cout << "-";
    }
    for(i = 0; i < 3; i++){
      if(ds[i] != 0){
	break;
      }
    }
    if(i == 3){
      cout << 0;
    }else{
      cout << ds[i];
      for(i++; i < 3; i++){
	printf("%03d", ds[i]);
      }
    }
    cout << endl;
  }
}
