/**
 * @Author: Author
 * @Date: 2023-07-13 16:42:27
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-13 16:42:27
 * @Description: 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000
*/


/**
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n^2)
 * dp[i][j]: 字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]
 * 转移方程:
 if(s[i] == s[j]):
    dp[i][j] = dp[i+1][j-1] + 2
 else:
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
*/

class Solution{
    public:
    int longestPalindromeSubseq(string s){
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--){
            for (int j = i + 1; j < s.size(); j++){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};