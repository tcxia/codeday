/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

// @lc code=start
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
    bool isPalindrome(string subs) {
        int n = subs.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            if (subs[left] != subs[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void findSubString(string s, string ans, vector<string>& substr) {
        if (s.length() == 0) {
            substr.push_back(ans);
            return;
        }

        findSubString(s.substr(1), ans + s[0], substr);
        findSubString(s.substr(1), ans, substr);
    }

   public:
    int countPalindromicSubsequencesv2(string s) {
        vector<string> strsubs;

        int n = s.size();
        findSubString(s, "", strsubs);

        set<string> sans(strsubs.begin(), strsubs.end());
        strsubs.assign(sans.begin(), sans.end());

        int count = 0;

        for (int i = 0; i < strsubs.size(); i++) {
            if (isPalindrome(strsubs[i]) && strsubs[i] != "") {
                count++;
            }
        }

        int maxv = pow(10, 7) + 7;
        if (count >= maxv) {
            count = count % maxv;
        }

        return count;
    }

    // dp[i][j] 表示 s[i, j]这段字符串的不同回文子串个数

    /**
     * 如果s[i] == s[j], 需要判断[i, j]这一段中有多少字符与s[i]不相等
     *  1. 如果中间没有和s[i]相同的字母，例如"aba"，那么dp[i][j] = dp[i+1][j-1]*2 + 2
     *      dp[i+1][j-1]*2 代表dp[i+1][j-1]可以独立存在，也可以外层包裹s[i], s[j]，所以需要*2
     *      +2代表"a"和"aa"
     *  2. 如果中间只有一个和s[i]相同的字母，就是"aaa"，那么dp[i][j] = dp[i+1][j-1]*2+1
     *      dp[i+1][j-1]*2和上面一致
     *      +1单独计算"aa"，而"a"在dp[i-1][j-1]已经计算过了
     *  3. 中间至少有两个和s[i]相同的字母，比如"aaaaaa"，那么dp[i][j] = dp[i+1][j-1] * 2 - dp[left+1][right-1];
     * 否则dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]
     */

    int countPalindromicSubsequencesv3(string s) {
        int n = s.size(), MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1));
        for (int i = 1; i <= n; i++) dp[i][i]++;
        for (int len = 2; len <= n; len++) {
            deque<int> q[4];
            for (int i = 1; i <= n; i++) {
                q[s[i - 1] - 'a'].push_back(i);
                int j = i - len + 1;
                if (j >= 1) {
                    for (int k = 0; k < 4; k++) {
                        while (q[k].size() && q[k].front() < j) q[k].pop_front();
                        if (q[k].size()) {
                            dp[j][i]++;
                            int l = q[k].front(), r = q[k].back();
                            if (l < r) {
                                dp[j][i] = (dp[j][i] + dp[l + 1][r - 1]) % MOD;
                            }
                        }
                    }
                }
            }
        }
        return (dp[1][n] + MOD - 1) % MOD;
    }

    int countPalindromicSubsequences(string s) {
        int strSize = s.size(), M = 1e9 + 7;
        vector<vector<int>> dp(strSize, vector<int>(strSize, 0));
        for (int i = 0; i < strSize; i++) {
            dp[i][i] = 1;
        }
        for (int i = strSize - 2; i >= 0; --i) {
            for (int j = i + 1; j < strSize; ++j) {
                if (s[i] == s[j]) {
                    // left用于寻找与s[i]相同的左端第一个下标，right用于寻找与s[i]相同的右端第一个下标
                    int left = i + 1, right = j - 1;
                    while (left <= right && s[left] != s[i]) {
                        ++left;
                    }
                    while (left <= right && s[right] != s[i]) {
                        --right;
                    }
                    if (left > right) {
                        // 情况1
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        // 情况2
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        // 情况3
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = (dp[i][j] < 0) ? dp[i][j] + M : dp[i][j] % M;
            }
        }
        return dp[0][strSize - 1];
    }
};
// @lc code=end

int main() {
    Solution solve;
    solve.countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba");
}