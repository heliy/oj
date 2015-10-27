#include<stdio.h>
#include<math.h>

int p3[101];

int main(){
  int a, b, c, d, n;
  for(a = 0; a <= 100; a++){
    p3[a] = pow(a, 3);
  }
  scanf("%d", &n);
  for(a = 2; a <= n; a++){
    for(b = 2; b < a; b++){
      for(c = b; c < a; c++){
	for(d = c; d < a; d++){
	  if(p3[a] == (p3[b]+p3[c]+p3[d])){
	    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	  }
	}
      }
    }
  }
  return 0;
}
