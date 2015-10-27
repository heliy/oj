#include<iostream>
#include<cmath>
#define COS120 (-1*0.5)
#define SWAP(A,B) t = (A); (A) = (B); (B) = t;
using namespace std;

double vcos(int x1, int y1, int x2, int y2){
  return (x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
}

bool isok(int x1, int y1, int x2, int y2, int x3, int y3){
    double c1 = vcos(x1, y1, x2, y2);
    double c2 = vcos(x2, y2, x3, y3);
    double c3 = vcos(x1, y1, x3, y3);
    if(c1 >= COS120 && c2 >= COS120 && c3 >= COS120){
      return false;
    }else{
      return true;
    }  
}

int main(){
  int n, x1, x2, x3, y1, y2, y3, r, t;
  cin >> n;
  while(cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
    double c1 = vcos(x1, y1, r, 0);
    double c2 = vcos(x2, y2, r, 0);
    double c3 = vcos(x3, y3, r, 0);
    bool r = true;
    if(c2 < c3){
      SWAP(c2, c3);
      SWAP(x2, x3);
      SWAP(y2, y3);
    }
    if(c1 < c2){
      SWAP(c1, c2);
      SWAP(x1, x2);
      SWAP(y1, y2);
    }
    if(c2 < c3){
      SWAP(c2, c3);
      SWAP(x2, x3);
      SWAP(y2, y3);
    }

    r = (isok(x1, y1, x2, y2, x3, y3) && isok(x2, y2, x3, y3, x1, y1) 
	&& isok(x3, y3, x1, y1, x2, y2));
    if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0)){
      r = false;
    }
    if(r){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
