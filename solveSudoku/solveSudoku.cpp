#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // 判断行里是否有重复
            if (board[row][i] == val) return false;
        }

        for (int j = 0; j < 9; j++) { // 判断列里是否有重复
            if (board[j][col] == val) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格是否有重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

   public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};



int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};


    Solution solve;
    solve.solveSudoku(board);
}