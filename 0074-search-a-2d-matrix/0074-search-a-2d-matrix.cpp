class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // coloumns
        
        // considering 1D array
        int low = 0, high = m *n -1;
        while(low <= high) {
            int mid = low + (high-low) / 2;
            int midVal = matrix[mid/n][mid%n];
            if (target == midVal ) {
                return true;
            } 
            if (target > midVal) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return false;
    }
};