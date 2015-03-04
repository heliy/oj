#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
  int n, ni;
  double a, b;
  scanf("%d", &n);
  for(ni = 0; ni < n; ni++){
    scanf("%lf %lf", &a, &b);
    printf("%d\n", (int)(log10(b)/log10(a)));
  }
}
