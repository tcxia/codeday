/**
 * @Author: Author
 * @Date: 2023-07-03 17:18:00
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-03 17:18:00
 * @Description: 给定整数数组，找到其中最长严格递增子序列的长度
*/

/**
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n)
 * dp[i]: 表示i之前包括i以内的nums[i]结尾的最长递增子序列的长度
 * 转移方程: 
 *  位置i的最长升序子序列等于j从0到i-1各位置的最长升子序列 + 1的最大值
 *  if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
 * 这里不是要dp[i]和dp[j] + 1进行比较，而是要取dp[j] + 1 的最大值
*/


class Solution{
    public:
    int lengthOfLTS(vector<int>& nums){
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};