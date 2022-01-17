#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j] 表示s的第i个字母在t的第j个字母对应
 * if dp[i][j] == dp[i-1][j-1] + 1
 * dp[i][j] false
 *
 */
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return true;
    }

    bool isSubsequencev2(string s, string t) {
        int ls = 0;
        int lt = 0;
        while (ls < s.size() && lt < t.size()) {
            if (s[ls] == t[lt]) ls++;
            lt++;
        }
        if (ls == s.size())
            return true;
        else
            return false;
    }
};
