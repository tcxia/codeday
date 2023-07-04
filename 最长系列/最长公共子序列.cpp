/**
 * @Author: Author
 * @Date: 2023-07-04 17:07:36
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-04 17:07:36
 * @Description: 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度
*/

/**
 * 时间复杂度: O(n x m), n和m分别是text1和text2的长度 
 * 空间复杂度: O(n x m)
 * dp[i][j]: 长度为[0, i-1]的字符串text1 和 长度为[0, j - 1]的字符串text2的最长公共子序列
 * 转移方程
 * text1[i - 1] == text2[j - 1]   dp[i][j] = dp[i - 1][j - 1] + 1
 * text1[i - 1] != text2[j - 1]   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
*/

class Solution{
    public:
    int longestCommonSubSequence(string text1, string text2){
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0)); // 顺序从第2个开始递推
        for (int i = 1; i < text1.size(); ++i){
            for (int j = 1; j < text2.size(); ++j){
                if (text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};