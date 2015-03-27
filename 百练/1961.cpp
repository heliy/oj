#include<iostream>

using namespace std;

/* TLE 要用KMP*/

char line[1000000];

int main(){
  int n = 0, len;
  while(cin >> len && len){
    cin >> line;
    n++;
    cout << "Test case #" << n << endl;
    int l, k, mae, i, j, sub, max;
    for(mae = 1, l = 2; l <= len; l++){
      max = l/2;
      for(sub = mae; sub <= max; sub++){
	if(l%sub == 0){
	  k = l/sub;
	  bool issame = true;
	  for(i = 1; i < k; i++){
	    for(j = 0; j < sub; j++){
	      if(line[i*sub+j] != line[j]){
		issame = false;
		break;
	      }
	    }
	    if(!issame){
	      break;
	    }
	  }
	  if(issame){
	    cout << l << " " << k << endl;
	    mae = sub;
	    break;
	  }
	}
      }
    }
    cout << endl;
  }
}
