#include<iostream>
#include<cstdio>

#include<cmath>
using namespace std;

/* AC */


int a, b, c, xi, yi;
double x, y;

double getDis(double x1){
  double y1 = a*x1*x1+b*x1+c;
  return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

int main(){
  cin >> a >> b >> c >> xi >> yi;
  x = (double)xi;
  y = (double)yi;
  double x1, x2, x3, x4, d1, d2, d3, d4, tmp, y1, y2;
  if(a == 0){
    x1 = x;
    y1 = b*x1+c;
    y2 = y;
    x2 = (y2-c)/b;
    d1 = fabs(y1-y);
    d2 = fabs(x2-x);
    d3 = sqrt((x2-x)*(x2-x)+(y1-y)*(y1-y));
    if(d3 == 0){
      printf("%.3f\n", 0.0);
    }else{
      d4 = d1*d2/d3;
      printf("%.3f\n", d4);
    }
    return 0;
  }
  x1 = (double)b/(-2*a);
  if(x1 == x){
    tmp = (4*a*c-b*b)/(double)(4*a);
    if((a-0)*(y-tmp) > 0){
      tmp = sqrt(b*b-4*a*(c-y))/(2*a);
      if(tmp > 0){
	x4 = x1+tmp;
      }else{
	x4 = x1-tmp;
      }
    }else{
      printf("%.3f\n", fabs(tmp-y));
      return 0;
    }
  }else if(x1 > x){
    x4 = x1;
    x1 = x;
  }else{
    x4 = x;
  }
  while(true){
    x2 = (x4-x1)/3+x1;
    x3 = x4+x1-x2;
    // printf("xss: %f %f %f %f\n", x1, x2, x3, x4);
    d1 = getDis(x1);
    d2 = getDis(x2);
    d3 = getDis(x3);
    d4 = getDis(x4);
    // printf("dis: %f %f %f %f\n", d1, d2, d3, d4);
    if(fabs(x2-x3) < 0.00001){
      break;
    }
    if(d2 < d3){
      x4 = x3;
    }else{
      x1 = x2;
    }
  }
  d2 = sqrt(getDis(x2));
  // if(((int)(d2*10000)%10) >= 5){
  //   d2 += 0.001;
  // }
  printf("%.3f\n", d2);
}
