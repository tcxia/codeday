/**
 * @Author: Author
 * @Date: 2023-07-03 17:40:52
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-03 17:40:52
 * @Description: 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度
*/



/**
 * 时间复杂度: O(n x m)
 * 空间复杂度: O(n x m)
 * dp[i][j]: 以下标i-1为结尾的A和以下标j-1为结尾的B，最长重复子数组的长度为dp[i][j]
 * 转移方程
 * if (numsA[i-1] == numsB[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1
*/


class Solution{
    public:
    int findLength(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); ++i){
            for (int j = 1; j <= nums2.size(); ++j){
                if (nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i-1][j-1] + 1
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};