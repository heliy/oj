#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

/* WA 求测试数据*/

int jury[22];
int atte[210][2];
int mins[210];

int main(){
  int m, n, i, j = 0, k, s, s1, s2, ki, min1, min2, k1, k2;
  while(cin >> n >> m && n){
    j++;
    for(i = 0; i < n; i++){
      cin >> atte[i][0] >> atte[i][1];
    }
    cout << "Jury #" << j << endl;
    if(n == 1){
      cout << "Best jury has value " << atte[0][0] << " for prosecution and value " << atte[0][1] << " for defence: \n 1" << endl << endl;
      continue; 
    }
    min1 = min2 = 0;
    for(i = 0; i < m; i++){
      jury[i] = i;
      min1 += atte[i][0];
      min2 += atte[i][1];
    }
    mins[m-1] = abs(min1 - min2);
    for(; i < n; i++){
      int min = mins[i-1];
      ki = -1;
      for(k = 0; k < m; k++){
	//	cout << min1 << "," << atte[jury[k]][0] << "," << atte[i][0] << endl;
	s1 = min1 - atte[jury[k]][0] + atte[i][0];
	s2 = min2 - atte[jury[k]][1] + atte[i][1];
	//	cout << k << ": " << s1 << ", " << s2 << ": " << abs(s1-s2) << " -> " << min << endl;
	if((abs(s1-s2) < min) || ((abs(s1-s2) == min) && (s1+s2) > (min1+min2))){
	  min = abs(s1-s2);
	  ki = k;
	  k1 = s1;
	  k2 = s2;
	}
      }
      if(ki != -1){
	mins[i] = min;
	min1 = min1 - atte[jury[ki]][0] + atte[i][0];
	min2 = min2 - atte[jury[ki]][1] + atte[i][1];
	jury[ki] = i;
	//	cout << jury[0] << "; " << jury[1] << endl;
      }else{
	mins[i] = mins[i-1];
      }
    // cout << i <<": " << mins[i] << ", " << min1 << ", " << min2 << endl;

    }
    cout << "Best jury has value " << min1 << " for prosecution and value " << min2 << " for defence:" << endl;
    sort(jury, jury+m);
    for(i = 0; i < m; i++){
      cout << " " << jury[i]+1;
    }
    cout << endl << endl;
  }
  return 0;
}
