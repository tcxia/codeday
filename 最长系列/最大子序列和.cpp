/**
 * @Author: Author
 * @Date: 2023-07-04 17:31:52
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-04 17:31:52
 * @Description: 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
*/

/**
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * dp[i]: 到i为止的最大的连续子数组的和
 * 转移方程:
 * dp[i] = max(dp[i - 1] + nums[i], nums[i])
*/

class Solution{
    public:
    // 动态规划
    int maxSubArray(vector<int>& nums){
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }

    // 暴力策略
    int maxSubArray_baoli(vector<int>& nums){
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i){
            count = 0;
            for (int j = i; j < nums.size(); ++j){
                count += nums[j];
                result = count > result ? count : result;
            }
        }
        return result;
    }

    // 贪心策略
    int maxSubArray_tanxin(vector<int>& nums){
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i){
            count += nums[i];
            if (count > result){ // 取区间累计的最大值(相当于不断确定最大子序列终止位置)
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序列起始位置，因为遇到负数一定是拉低总和的
        }
        return result;
    }
};
