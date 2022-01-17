#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j]: 表示 [0, i-1] 为结尾的s的子序列 和 以[0, j-1]为结尾的t的出现个数 dp[i][j]
 *
 * if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1
 * else dp[i][j] = max(dp[i-1][j] + 1, dp[i][j-1] + 1)
 *
 * dp[i][j]: dp[i][0] = 1, dp[0][j] = 1
 *
 * 从前往后遍历
 *
 * dp[s.size()][t.size()] == dp[t.size()]
 *
 */

class Solution {
   public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++) dp[0][j] = 0;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};