#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 101
#define M 10001
#define MIN(A, B) ((A)<(B)?(A):(B))
#define MIN3(A, B, C) (MIN(MIN((A), (B)), (C)))
#define MAX N*N*M

using namespace std;

int A[N][N];
long long S[N][N][N][N];

long long setS(int i1, int i2, int j1, int j2){
  if(i1 == i2 && j1 == j2){
    return A[i1][i2];
  }else if(i1 == i2){
    return setS(i1, i2, j1, j2-1)+A[i1][j2];
  }else if(j1 == j2){
    return setS(i1, i2-1, j1, j2)+A[i2][j2];
  }else{
    
  }
}

int main(){
  int t, ti, m, n, i, j, num, k, i1, i2, j1, j2;
  long long sum, min;
  cin >> t;
  for(ti = 1; ti <= t; ti++){
    num = 0;
    scanf("%d %d", &m, &n);
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
	scanf("%d", &A[i][j]);
      }
    }

    for(i1 = 0; i1 < m; i1++){
      for(j1 = 0; j1 < n; j1++){
	for(i2 = i1; i2 < m; i2++){
	  for(j2 = j1; j2 < n; j2++){
	    if(j2 == j1 && i2 == i1){
	      S[i1][i2][j1][j2] = A[i1][j1];
	    }else if(i1 == i2){
	      S[i1][i2][j1][j2] = S[i1][i2][j1][j2-1] + A[i1][j2];
	    }else if(j1 == j2){
	      S[i1][i2][j1][j2] = S[i1][i2-1][j1][j2] + A[i2][j1];
	    }else{
	      min = S[i1][i2-1][j1][j2-1] + A[i2][j2];
	      min = MIN3(min, S[i1][i2-1][j1+1][j2]+A[i2][j1], S[i1][i2-1][j1][j2]+A[i2][j1]);
	      for(k = j1+1; k < j2; k++){
		min = MIN3(min, S[i1][i2-1][j1][k-1]+S[i1][i2-1][k+1][j2]+A[i2][k], S[i1][i2-1][j1][j2]+A[i2][k]);
	      }
	      min = MIN3(min, S[i1][i2-1][j1][j2-1]+A[i2][j2], S[i1][i2-1][j1][j2]+A[i2][j2]);
	      min = MIN3(min, S[i1+1][i2][j1][j2-1]+A[i1][j2], S[i1][i2][j1][j2-1]+A[i1][j2]);
	      for(k = i1+1; k < i2; k++){
		min = MIN3(min, S[i1][k-1][j1][j2-1]+S[k+1][i2][j1][j2-1]+A[k][j2], S[i1][i2][j1][j2-1]+A[k][j2]);
	      }
	      min = MIN3(min, S[i1][i2-1][j1][j2-1]+A[i2][j2], S[i1][i2][j1][j2-1]+A[i2][j2]);
	      S[i1][i2][j1][j2] = min;
	    }
	    cout << i1 << ", " << i2 << ", " << j1 << ", " << j2 << ": " << S[i1][i2][j1][j2] << endl;
	  }
	}
      }
    }
    //   for(j = 0; j < n; j++){
    // 	min = MAX;
    // 	// cout << i << ", " << j << endl;
    // 	if(i*j == 0){
    // 	  if(i == j){
    // 	    min = A[i][j];
    // 	  }else{
    // 	    if(i == 0){
    // 	      min = S[i][j-1] + A[i][j];
    // 	    }else{
    // 	      min = S[i-1][j] + A[i][j];	      
    // 	    }
    // 	  }
    // 	}else{
    // 	  if(i != 0){
    // 	    for(k = 0; k <= j; k++){
    // 	      // cout << "1: " << S[i-1][j] << " + " <<  A[i][k] << endl;
    // 	      min = MIN(min, S[i-1][j]+A[i][k]);
    // 	    }
    // 	  }
    // 	  if(j != 0){
    // 	    for(k = 0; k <= i; k++){
    // 	      // cout << "2: " << S[i][j-1] << " + " << A[i][k] << endl;
    // 	      min = MIN(min, S[i][j-1]+A[k][j]);
    // 	    }
    // 	  }
    // 	  // cout << "3: " << S[i-1][j-1] << " + " << A[i][k] << endl;
    // 	  min = MIN(min, S[i-1][j-1]+A[i][j]);
    // 	}
    // 	S[i][j] = min;
    // 	cout << min << " ";
    //   }
    //   cout << endl;
    // }
    cout << "Case " << ti << ": " << S[0][m-1][0][n-1] << endl;
  }
}

// struct tri{
//   int i;
//   int j;
//   int value;
// };

// bool cmp(struct tri t1, struct tri t2){
//   return (t1.value < t2.value);
// }

// struct tri tris[N*N];
// bool rows[N], cols[N];

      //      rows[i] = true;
	// scanf("%d", &tris[num].value);
	// tris[num].i = i;
	// tris[num].j = j;
	// num++;

    // for(j = 0; j < n; j++){
    //   cols[j] = true;
    // }
    // sort(tris, tris+num, cmp);

    // sum = 0;
    // for(k = 0; k < num; k++){
    //   i = tris[k].i;
    //   j = tris[k].j;
    //   if(rows[i] || cols[j]){
    // 	sum += tris[k].value;
    // 	rows[i] = false;
    // 	cols[j] = false;
    //   }
    // }
