#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> result;
    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        int count = 0;
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 检查45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // 检查135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)){ // 验证合法就可以放置
                chessboard[row][col] == 'Q'; // 放置
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.'; // 回溯
            }
        }
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};