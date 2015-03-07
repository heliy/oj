#include<stdio.h>
#include<iostream>
using namespace std;

float prices[10] = {
  28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65,
};

int main(){
  int k, ki, i, num;
  cin >> k;
  for(ki = 0; ki < k; ki++){
    float sum = 0;
    for(i = 0; i < 10; i++){
      cin >> num;
      sum += prices[i]*num;      
    }
    printf("%.2f\n", sum);
  }
}
