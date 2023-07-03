/**
 * @Author: Author
 * @Date: 2023-07-03 17:31:31
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-03 17:31:31
 * @Description: 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度
*/

/**
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * dp[i]: 以下标i为结尾的连续递增的子序列长度
 * 转移方程: 
 *  位置i的最长升序子序列等于j从0到i-1各位置的最长升子序列 + 1的最大值
 *  if (nums[i] > nums[i-1]) dp[i] = dp[i - 1] + 1
*/

class Solution{
    public:
    int findLengthOfLCIS(vector<int>& nums){
        if (nums.size() <= 1) return nums.size();

        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};