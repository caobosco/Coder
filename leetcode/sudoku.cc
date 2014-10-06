#include <cstdio>
#include <vector>
#include <cstring>


#define M 9
#define S 3

using namespace std;

class Solution {
    bool isValidSudoku(vector<vector<char> > &board, int x, int y){
        int arr[10];
        //x 
        memset(arr, 0, sizeof(arr));
        for(int j = 0; j < M; j++){
            if(board[x][j] != '.'){
                if(arr[board[x][j] - '0'] != 0)
                    return 0;
                else
                    arr[board[x][j] - '0'] = 1;
            }
        }
        //y
        memset(arr, 0, sizeof(arr));
        for(int j = 0; j < M; j++){
            if(board[j][y] != '.'){
                if(arr[board[j][y] - '0'] != 0)
                    return 0;
                else
                    arr[board[j][y] - '0'] = 1;
            }
        }
        
        x = x/3; y = y/3;
        memset(arr, 0, sizeof(arr));
        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++){
                if(board[3*x+ k][3*y+ l] != '.'){
                    if(arr[board[3*x+ k][3*y+ l] - '0'] != 0)
                        return 0;
                    else
                        arr[board[3*x+ k][3*y+ l] - '0'] = 1;
                }
            }
        }
        return 1;
    }
    
    bool backtracking(vector<vector<char> > &board, int x, int y){
        if (x == M)
            return 1;
        for (int j = y; j < M; j++) {
            if (board[x][j] == '.') {
                for (int k = 1; k <= M; k++) {
                    board[x][j] = k + '0';
                    if(isValidSudoku(board, x, j)&& backtracking(board, x + (j+1)/M, (j+1)%M))
                        return true;
                }
                board[x][j] = '.';
                return false;
            }
        }
        
        for (int i = x+ 1; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == '.') {
                    for(int k = 1; k <= M; k++){
                        board[i][j] = k + '0'; 
                        if(isValidSudoku(board, i, j) && backtracking(board, i + (j+1)/M, (j+1)%M))
                            return true;
                    }
                    board[x][j] = '.';
                    return false;
                }
            }
        }
        if(x == M )
            return true;
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char> > &board) {
        backtracking(board, 0, 0);
    }
};
int main(){
    vector<char> tmp(M);
    vector<vector<char> > ret(M, tmp);    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &ret[i][j]);
        }
    }
    
    Solution sol;
    sol.solveSudoku(ret);
    return 0;
}
