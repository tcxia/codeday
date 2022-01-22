#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int ret = INT32_MAX;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        int downSum = 0;
        for (int i = 0; i < m; i++) {
            downSum += grid[i][0];
            dp[i][0] = downSum;
        }

        int rightSum = 0;
        for (int j = 0; j < n; j++) {
            rightSum += grid[0][j];
            dp[0][j] = rightSum;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    Solution solve;
    int ret = solve.minPathSum(grid);
    cout << ret << endl;
}