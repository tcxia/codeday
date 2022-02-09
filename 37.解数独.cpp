/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
    bool isValid(int row, int col, vector<vector<char>>& board, char val){
        for(int i = 0; i < 9; i++){
            if (board[row][i] == val){
                return false;
            }
        }

        for(int j = 0; j < 9; j++){
            if (board[j][col] == val){
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if (board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }


    bool traserval(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] != '.') continue; // 只有空白位置填数字
                for(char k = '1'; k <= '9'; k++){
                    if(isValid(i, j, board, k)){
                        board[i][j] = k;
                        if (traserval(board)) return true;
                        board[i][j] = '.'; // 回溯
                    }
                }
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        traserval(board);
    }
};
// @lc code=end

