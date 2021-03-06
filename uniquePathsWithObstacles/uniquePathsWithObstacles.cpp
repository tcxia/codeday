#include <vector>
#include <iostream>

using namespace std;
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j] 代表到达[i, j]点的路径数
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // for(int i = 0; i < obstacleGrid.size(); i++) dp[i][0] = 1
        // for(int j = 0; j < obstacleGrid[0].size(); j++) dp[0][j] = 1

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;  //
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;  //

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution solve;
    int ret = solve.uniquePathsWithObstacles(obstacleGrid);
    cout << ret << endl;
}