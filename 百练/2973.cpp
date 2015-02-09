#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
  char line[50];
  while(true){
    fgets(line, 50, stdin);
    if(line[0] == '0'){
      break;
    }
    int p, n = strlen(line);
    long x;
    for(n -= 2, p = 2, x = 0; n >= 0; n--, p *= 2){
      x += (line[n] - '0') * (p -1);
    }
    printf("%ld\n", x);
  }
  return 0;
}
