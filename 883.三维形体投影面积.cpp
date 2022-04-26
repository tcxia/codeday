/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();     // 行数
        int n = grid[0].size();  // 列数
        // y轴代表每一行最大值的和
        int sumM = 0;
        for (int i = 0; i < m; i++) {
            int tmp = *max_element(grid[i].begin(), grid[i].end());
            sumM += tmp;
        }
        cout << sumM << endl;
        // x轴代表每一列最大值的和
        int sumN = 0;
        for (int i = 0; i < n; i++) {
            int value = grid[0][i];
            for (int j = 1; j < m; j++) {
                if (grid[j][i] > value) value = grid[j][i];
            }
            sumN += value;
        }
        cout << sumN << endl;
        // z所有非零元素的计数
        int sumZ = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) sumZ++;
            }
        }
        cout << sumZ << endl;
        return sumM + sumN + sumZ;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> grid = {{1, 0}, {5, 4}};

    Solution solve;
    solve.projectionArea(grid);
}