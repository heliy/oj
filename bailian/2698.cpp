#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int per[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int cases = 1;
int m[8][8];
void print(){
  int i, j;
  printf("No. %d\n", cases++);
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      m[i][j] = 0;
    }
  }
  for(i = 0; i < 8; i++){
    m[per[i]-1][i] = 1;
  }
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}
// 15863724
int main(){
  do{
    int i, j;
    bool out = false;
    for(i = 0; i < 8; i++){
      for(j = i+1; j < 8; j++){
	if(abs(j-i) == abs(per[i] - per[j])){
	  out = true;
	  break;
	}
      }
      if(out){
	break;
      }
    }
    if(!out){
      print();
    }
  }while(next_permutation(per, per+8)); 
}
