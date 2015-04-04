#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  int x1, x2, x3, x4, x5, x6, x7;
  int count[43] = { 0, 0, 0, 0, 0, 0, 0, 1, 7, 28, 84, 210, 462, 917, 1667, 2807, 4417, 6538, 9142, 12117, 15267, 18327, 20993, 22967, 24017, 24017, 22967, 20993, 18327, 15267, 12117, 9142, 6538, 4417, 2807, 1667, 917, 462, 210, 84, 28, 7, 1, };
  int sum = 0;
  for(x1 = 0; x1 < 43; x1++){
    sum += count[x1];
  }
  // for(x1 = 0; x1 <= 43; x1++){
  //   count[x1] = 0;
  // }
  // for(x1 = 1; x1 <= 6; x1++){
  //   for(x2 = 1; x2 <= 6; x2++){
  //     for(x3 = 1; x3 <= 6; x3++){
  // 	for(x4 = 1; x4 <= 6; x4++){
  // 	  for(x5 = 1; x5 <= 6; x5++){
  // 	    for(x6 = 1; x6 <= 6; x6++){
  // 	      for(x7 = 1; x7 <= 6; x7++){
  // 		count[x1+x2+x3+x4+x5+x6+x7]++;
  // 		sum++;
  // 	      }
  // 	    }
  // 	  }
  // 	}
  //     }
  //   }
  // }
  // cout << "{ ";
  // for(x1 = 0; x1 < 43; x1++){
  //   cout << count[x1] << ", ";
  // }
  // cout << "}" << endl;
  while(cin >> x1){
    if(x1 > 42){
      cout << "0.0000" << endl;
    }else{
      printf("%.4f\n", count[x1]/(double)sum);
    }
  }
}
