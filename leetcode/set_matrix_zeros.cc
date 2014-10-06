#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool is_first_row_zero = false, is_first_column_zero = false;
        int row_length = matrix.size(), column_length = matrix[0].size();
        for (int i = 0; i < column_length; i++)
            if (matrix[0][i] == 0)
                is_first_row_zero = true;
        for (int i = 0; i < row_length; i++)
            if (matrix[i][0] == 0)
                is_first_column_zero = true;
        
        for(int i = 1; i < row_length; i++) {
            for (int j = 1; j < column_length; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < column_length; i++) {
            if (matrix[0][column_length] == 0) {
                for(int j = 1; j < row_length; i++)
                    matrix[j][i] = 0;
            }
        }
        
        for (int i = 1; i < row_length; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < column_length; j++)
                    matrix[i][j] = 0;
            }
        }
        
        if (is_first_row_zero) {
            for (int i = 0; i < column_length; i++)
                matrix[0][i] = 0;
        }
        
        if (is_first_column_zero) {
            for (int i = 0; i < row_length; i++)
                matrix[i][0] = 0;
        }   
    }
};

int main (){
    vector<vector<int> > matrix(4, vector<int> (5, 0) );
    Solution sol;
    sol.setZeroes(matrix);
    return 0;
}
