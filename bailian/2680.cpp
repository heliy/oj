#include<stdio.h>

using namespace std;

int main(){
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    char s[10];
    float wbc, rbc;
    float hgb, hct, plt;
    scanf("%s %f %f %f %f %f", s, &wbc, &rbc, &hgb, &hct, &plt);
    int c = 0;
    if(wbc < 4.0 || wbc > 10.0){
      c++;
    }
    if(rbc < 3.5 || rbc > 5.5){
      c++;
    }
    if(plt < 100 || plt > 300){
      c++;
    }
    if(s[0] == 'f'){
      if(hgb < 110 || hgb > 150){
	c++;
      }
      if(hct < 36 || hct > 40){
	c++;
      }
    }else{
      if(hgb < 120 || hgb > 160){
	c++;
      }
      if(hct < 42 || hct > 48){
	c++;
      }
    }
    if(c == 0){
      printf("normal\n");
    }else{
      printf("%d\n", c);
    }
  }
}
