/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start

#include <vector>

using namespace std;
class Solution {
    int m, n;
    vector<vector<bool>> visited;

public:
    // 深度优先遍历
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size(); // 行数初始化
        this->n = grid[0].size(); // 列数初始化
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false)); // 是否访问标签初始化

        for(int i = 0; i < m; i++){
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }

        for(int j = 1; j < n - 1; j++){
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        int enclaves = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }

    void dfs(const vector<vector<int>>&grid, int row, int col){
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col]==0 || visited[row][col]){
            return;
        }
        visited[row][col] = true;
        for(auto& dir : dirs){
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }
};
// @lc code=end

