#include <vector>
#include <iostream>

using namespace std;

class Solution {
    string path;
    bool backtracking(string word, vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int k){
        if (board[i][j] != word[k]){
            return false;
        }else if (k == word.size() - 1){
            return true;
        }
        visited[i][j] = true;
        bool result = false;
        vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(const auto& dir : directions){
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()){
                if (!visited[newi][newj]){
                    bool flag = backtracking(word, board, visited, newi, newj, k + 1);
                    if (flag){
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
        
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                bool flag = backtracking(word, board, visited, i, j, 0);
                if (flag){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCED";

}