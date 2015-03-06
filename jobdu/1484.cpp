#include<iostream>
#include<cstdio>

using namespace std;

char line[200];
char f[100], d[100], type;

int mileage(int dis, char type){
  switch(type){
  case 'F': return (dis*2);
  case 'B': 
    if(dis%2 == 0){
      return (int)(dis*1.5);
    }else{
      return (int)(dis*1.5)+1;
    }
  case 'Y': return (dis < 500)?500:dis;
  default: return -1;
  }
}

int main(){
  while(fgets(line, 200, stdin) != NULL){
    if(line[0] == '#'){
      break;
    }
    int sum, dis;
    sscanf(line, "%s %s %d %c", f, d, &dis, &type);
    sum = mileage(dis, type);
    while(fgets(line, 200, stdin) != NULL){
      if(line[0] == '0'){
        break;
      }
      sscanf(line, "%s %s %d %c", f, d, &dis, &type);
      sum += mileage(dis, type);
    }
    cout << sum << endl;
  }
}
