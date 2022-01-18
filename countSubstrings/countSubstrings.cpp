#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j]表示区间[i, j]是否为回文
 * if(s[i] != s[j])  dp[i][j] false
 * else{
 *  if i == j dp[i][j] true
 *  if j-i == 1 dp[i][j] true
 *  if j -i > 1 dp[i][j] = dp[i+1][j-1]
 * }
 */
class Solution {
    bool isPalindromic(string s) {
        int ls = 0;
        int rs = s.size() - 1;
        while (ls <= rs) {
            if (s[ls] != s[rs]) {
                return false;
            } else {
                ls++;
                rs++;
            }
        }
        return true;
    }

   public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ret = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        ret++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        ret++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ret;
    }
};