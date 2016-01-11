#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

#define N 100

using namespace std;

int isis[4][N];
int nums[4];
char names[4];

void print(){
     int i, j;
     for(i = 1; i < 4; i++){
           cout << i  << ", " << nums[i] << ": ";
           for(j = 0; j < nums[i]; j++){
                 cout << isis[i][j] << " ";
           }
           cout << endl;
     }
     cout << endl;
}

void rem(int f, int t, int n){
     if(n <= 0){
          return;
     }
     if(n == 1){
//          cout << f <<", " << t << ": "<< nums[f] << nums[t] << (nums[f]-n) << endl;
          printf("%d:%c->%c\n", isis[f][nums[f]-n], names[f], names[t]);
          isis[t][nums[t]] = isis[f][nums[f]-n];
          nums[f]--;
          nums[t]++;
//          print();
     }else{
           int another = 6-f-t;
           rem(f, another, n-1);
           rem(f, t, 1);
           rem(another, t, n-1);
     }
}


int main(){
    int n, i;
    scanf("%d %c %c %c", &n, names+1, names+2, names+3);
    nums[1] = n;
    nums[3] = nums[2] = 0;
    for(i = 0; i < n; i++){
          isis[1][i] = n-i;
    }
    rem(1, 3, n);
//    system("pause");
}
