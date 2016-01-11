#include<iostream>
#include<cstdio>
#include<vector>
#include<stdlib.h>
using namespace std;

#define N 100
int mat[N][N];
bool isout[N];

int next(int n){
    int i, j;
    for(i = 1; i <= n; i++){
          if(isout[i]){
                       continue;
          }
//          cout << i <<": ";
          bool ok = true;
          for(j = 1; j <= n; j++){
//                cout << mat[j][i] << ", ";
                if(!isout[j] && mat[j][i] > 0){
                             ok = false;
                             break;
                }
          }
//          cout << endl;
          if(ok){
          return i;
          }
    }
    return -1;
}


int main(){
    int n, a, i, s, t;
    cin >> n >> a;
//    vector<vector<int> > mat = vector<vector<int>(n+1) >(n+1);
    for(i = 0; i < a; i++){
          cin >> s >> t;
          mat[s][t] = 1;
    }
    for(i = 1; i <= n; i++){
          isout[i] = false;
    }
    i = 0;
    while(i < n){
            t = next(n);
            i++;
            isout[t] = true;
            cout << "v" << (t);
            if(i < n){
                 cout << " ";
            }
    }
    cout << "\n";
}
