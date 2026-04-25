class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int f_row = matrix.size();
        int f_col = matrix[0].size();
        int l = 0;
        int r = f_row * f_col - 1;
        int m = 0;
        while(l <= r){
            m = l + (r - l)/2;
            int row = m/f_col;
            int col = m%f_col;
            if(target > matrix[row][col]){
                l = m + 1;
            }
            else if(target < matrix[row][col]){
                r = m - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
