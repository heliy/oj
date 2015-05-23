/* AC 4ms */

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  int i, j;
  for(i = 0; i < matrixRowSize; i++){
    if(matrix[i][0] <= target && matrix[i][matrixColSize-1] >= target){
      for(j = 0; j < matrixColSize; j++){
	if(matrix[i][j] == target){
	  return true;
	}
      }
      return false;
    }
  }
  return false;
}
