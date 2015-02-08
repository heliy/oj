#include<stdio.h>
#include<algorithm>

using namespace std;

// char matrix[10][10];
// int used[11][11];

int main(){
  char word[100];
  int count[26];
  int m, n, p;
  scanf("%d %d %d", &m, &n, &p);
  int i, j;
  char c;
  for(i = 0; i < 26; i++){
    count[i] = 0;
  }
  for(i = 0; i < m; i++){
    scanf("%s", word);
    for(j = 0; word[j] != '\0'; j++){
      count[word[j] - 'A']++;
    }
  }
  for(i = 0; i < p; i++){
    scanf("%s", word);
    for(j = 0; word[j] != '\0'; j++){
      count[word[j] - 'A']--;
    }
  }
  for(i = 0; i < 26; i++){
    for(j = 0; j < count[i]; j++){
      printf("%c", i+'A');
    }
  }
  printf("\n");
}

// int m, n, p;

// int find(int begin, int x, int y){
//   if(x < 0 || y < 0 || x >= m || y >= n){
//     return 0;
//   }
//   if(word[begin] == '\0'){
//     return 1;
//   }
//   int is_find = 0;
//   if(matrix[x][y] == word[begin]){
//     if(find(begin+1, x+1, y)){
//       is_find = 1;
//     }
//     if(find(begin+1, x-1, y)){
//       is_find = 1;
//     }
//     if(find(begin+1, x, y+1)){
//       is_find = 1;
//     }
//     if(find(begin+1, x, y-1)){
//       is_find = 1;
//     }
//   }
//   if(is_find){
//     used[x][y] = 1;
//   }
//   return is_find;
// }

// int main(){
//   scanf("%d %d %d", &m, &n, &p);
//   int i, j, k;
//   for(i = 0; i < m; i++){
//     for(j = 0; j < n; j++){
//       scanf("%c", &matrix[i][j]);
//       used[i][j] = 0;
//     }
//   }
//   for(k = 0; k < p; k++){
//     scanf("%s", word);
//     if(word[0] == '\0'){
//       scanf("%s", word);      
//     }
//     for(i = 0; i < m; i++){
//       for(j = 0; j < n; j++){
// 	find(0, i, j);
//       }
//     }
//   }
//   for(k = 0, i = 0; i < m; i++){
//     for(j = 0; j < n; j++){
//       if(!used[i][j]){
// 	word[k++] = matrix[i][j];
//       }
//     }
//   }
//   sort(word, word+k);
//   printf("%s\n", word);
// }
