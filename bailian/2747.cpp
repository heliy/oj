#include<stdio.h>

using namespace std;

int main(){
  int c, ci;
  scanf("%d", &c);
  for(ci = 0; ci < c; ci++){
    int n, a1, a2, a3, max = 0;
    scanf("%d", &n);
    for(a1 = n; a1 >= 0; a1--){
      for(a2 = n; a2 >= 0; a2--){
	for(a3 = n; a3 >= 0; a3--){
	  int sum = a1+a2+a3;
	  if(sum > max){
	    if((a1+a2)%2 == 0 && (a2+a3)%3 == 0 && sum%5 == 0){
	      max = sum;
	    }
	  }
	}
      }
    }
    printf("%d\n", max);
  }
}
