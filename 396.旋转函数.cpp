/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int matmul(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int tmp = i * nums[i];
            sum += tmp;
        }
        return sum;
    }

    vector<int> reverseNums(vector<int> nums, int k, int n) {
        int j = n - k - 1;  // k = 1, j = 2
        reverse(nums.begin(), nums.begin() + j);
        reverse(nums.begin() + j, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }

   public:
    int maxRotateFunctionv2(vector<int>& nums) {
        int n = nums.size();
        int result = INT32_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> temp = reverseNums(nums, i, n);
            int sum = matmul(temp);
            result = sum > result ? sum : result;
            // cout << temp[0] << temp[1] << temp[2] << temp[3] << endl;
        }
        return result;
    }

    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++){
            f += i * nums[i];
        }
        int res = f;
        for (int i = n -1; i > 0; i--){
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }


};
// @lc code=end

int main() {
    vector<int> nums = {4, 3, 2, 6};

    Solution solve;
    int ret = solve.maxRotateFunctionv2(nums);

    cout << ret << endl;
}