#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j]表示区间[i,j]之间的最长回文子串
 * if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2
 * else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
 *
 *
 *
 */
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};