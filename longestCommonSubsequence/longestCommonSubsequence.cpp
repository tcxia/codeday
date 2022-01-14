#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] 表示 [0, i-1] 与 [0 j-1]相同的元素个数
        // if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1
        // dp[i][0] = 1  dp[0][j] = 1
        // 从前往后遍历
        // 返回dp[i][j]
        int ret;
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};