#include<cstdio>
#include<iostream>

#define N 22

using namespace std;

char a_string[N], b_string[N];
int a_ints[N], b_ints[N], result[N];

void string2ints(char* string, int* ints){
    int i, l, j;
    for(l = 0; l < N && string[l] != '\0' && string[l] != '\n'; i++){
        ;
    }
    for(i = l - 1, j = 0; i >= 0; i--, j++){
        ints[j] = string[i]-'0';
        cout << j << ": " << ints[j] << endl;
    }
    ints[j] = -1;
}

void tail(int* ints, int i){
    if(ints[i] != -1){
        for(;i < N && ints[i] >= 0; i++){
            int r = ints[i]+result[i];
            while(r > 9){
                result[i++]++;
                r -= 10;
            }
            result[i] = r;
        }
    }
}

int main(){
    int t, ti, i;
    cin >> t;
    for(ti = 1; ti <= t; ti++){
        cin >> a_string >> b_string;
        for(i = 0; i < N; i++){
            a_ints[i] = b_ints[i] = result[i] = 0;
        }
        string2ints(a_string, a_ints);
        string2ints(b_string, b_ints);
        for(i = 0; i < N && a_ints[i] >= 0 && b_ints[i] >= 0; i++){
            int r = a_ints[i]+b_ints[i]+result[i];
            while(r > 9){
                result[i++]++;
                r -= 10;
            }
            result[i] = r;
        }
        tail(a_ints, i);
        tail(b_ints, i);
        for(i = N-1; i >= 0; i--){
            if(result[i] != 0){
                break;
            }
        }
        cout << "Case " << ti << ":" << endl;
        cout << a_string << " + " << b_string << " = ";
        for(; i >= 0; i--){
            printf("%d", result[i]);
        }
        cout << endl << endl;
    }
}
