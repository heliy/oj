#include<stdio.h>
#include<string.h>

char array[100][500];

char ret[1000];

char *convert(char *s, int nRows) {
  if(nRows == 1){
    return s;
  }
  int len = strlen(s);
  int i, j, n, m;
  for(i = 0; i < nRows; i++){
    for(j = 0; j < 500; j++){
      array[i][j] = '\0';
    }
  }
  int ismid = 0;
  for(i = j = n = m = 0; n < len; n++){
    if(ismid == nRows){
      i = nRows/2;
      j++;
      ismid = 0;
      array[i][j] = s[n];
      /* printf("%d, %d: %c\n", i, j, s[n]); */
      i = 0;
      j++;
    }else{
      ismid++;
      array[i][j] = s[n];
      /* printf("%d, %d: %c\n", i, j, s[n]); */
      i++;
    }
  }
  n = 0;
  m = j;
  for(i = 0; i < nRows; i++){
    for(j = 0; j <= m; j++){
      if(array[i][j] != '\0'){
	ret[n++] = array[i][j];
      }
    }
  }
  ret[n] = '\0';
  return ret;
}

int main(){
  char string[] = "A";
  printf("%s\n", convert(string, 1));
}
