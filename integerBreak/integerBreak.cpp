#include <vector>
using namespace std;
class Solution {
   public:
    int integerBreak(int n) {
        // dp[i] 代表分拆数字i，可以得到最大乘积dp[i]
        // dp[i] = max( dp[i], max(dp[i-j] * j, (i-j) * j) )
        // dp[2] = 1
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};