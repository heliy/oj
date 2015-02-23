#include<stdio.h>
#define N 100000

using namespace std;

char en[N], de[N];
char info1[N], info2[N], info3[N];

int main(){
  int k1, k2, k3;
  while(scanf("%d %d %d", &k1, &k2, &k3) != EOF){
    if(k1 == 0 && k2 == 0 && k3 == 0){
      break;
    }
    scanf("%s", en);
    int i, j1, j2, j3;
    for(i = j1 = j2 = j3 = 0; en[i] != '\0' && en[i] != '\n'; i++){
      if(en[i] == '_' || en[i] >= 's'){
	info3[j3++] = en[i];
      }else if(en[i] <= 'i'){
	info1[j1++] = en[i];
      }else{
	info2[j2++] = en[i];
      }
    }
    info1[j1] = info2[j2] = info3[j3] = '\0';
    if(j1 != 0){
      k1 = k1%j1;
      if(k1 == 0){
        j1 = 0;
      }else{
        j1 -= k1;      
      }
    }
    if(j2 != 0){
      k2 = k2%j2;
      if(k2 == 0){
        j2 = 0;
      }else{
        j2 -= k2;      
      }
    }
    if(j3 != 0){
      k3 = k3%j3;
      if(k3 == 0){
        j3 = 0;
      }else{
        j3 -= k3;      
      }
    }
    for(i = 0; en[i] != '\0' && en[i] != '\n'; i++){
      if(en[i] == '_' || en[i] >= 's'){
	de[i] = info3[j3++];
	if(info3[j3] == '\0'){
	  j3 = 0;
	}
      }else if(en[i] <= 'i'){
	de[i] = info1[j1++];
	if(info1[j1] == '\0'){
	  j1 = 0;
	}
      }else{
	de[i] = info2[j2++];
	if(info2[j2] == '\0'){
	  j2 = 0;
	}
      }
      printf("%c", de[i]);
    }
    printf("\n");
  }
  return 0;
}
