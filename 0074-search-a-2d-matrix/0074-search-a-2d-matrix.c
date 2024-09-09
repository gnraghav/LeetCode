
bool searchMatrix(int** matrix, int matrixSize, int *matrixColSize, int target){
     int i=0, j=0;
    while(i<matrixSize) {
        if(target>matrix[i][*matrixColSize-1]) {
            i++;
        }else {
            while(j<*matrixColSize){
                if(target!=matrix[i][j]){
                    j++;
                } else {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}