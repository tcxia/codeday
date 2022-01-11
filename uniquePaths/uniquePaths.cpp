#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int uniquePaths(int m, int n) {
        // 1. 确定dp[i,j]的具体含义
        // dp[i, j] 表示从[0,0]出发到[i,j]有dp[i,j]条不同的路径
        // 2. 递推公式
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // 3. 初始化
        // for(int i = 0; i < m; i++) dp[i][0] = 1
        // for(int j = 0; j < n; j++) dp[0][j] = 1
        // 4. 确定遍历顺序
        // 从左到右一层一层遍历即可，保证dp[i][j]之前的dp[i-1][j]和dp[i][j-1]都是有赋值的

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solve;
    int ret = solve.uniquePaths(3, 7);
    cout << ret << endl;
}
