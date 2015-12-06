#include<iostream>
#include<stdlib.h>
#include<string>

#define N 35

using namespace std;

string currencies[N];
double arbitrage[N][N];

int index(string s){
    int i;
    for(i = 0; i < N; i++){
          if(currencies[i].compare(s) == 0){
              return i;
          }
    }
    return -1;
}

int main(){
    int n, i, j, k, m, index1, index2, t=0;
    double rate;
    string c1, c2;
    while(cin >> n){
        t++;
        if(n == 0){
             break;
        }
        for(i = 0; i < n; i++){
              cin >> currencies[i];
        }
        for(i = 0; i < n; i++){
              for(j = 0; j < n; j++){
                    arbitrage[i][j] = 0;
              }
              arbitrage[i][i] = 1;
        }
        cin >> m;
        for(i = 0; i < m; i++){
              cin >> c1 >> rate >> c2;
              index1 = index(c1);
              index2 = index(c2);
              arbitrage[index1][index2] = rate;
        }
        bool has = false;
        for(k = 0; k < n; k++){
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                    if(arbitrage[i][j] < arbitrage[i][k]*arbitrage[k][j]){
                        arbitrage[i][j] = arbitrage[i][k]*arbitrage[k][j];
                    }
                }
            }
        }
        for(i = 0; i < n; i++){
              if(arbitrage[i][i] > 1){
                  cout << "Case " << t << ": Yes\n";
                  has = true;
                  break;
              }
        }
        if(!has){
            cout << "Case " << t << ": No\n";
        }
    }
}
