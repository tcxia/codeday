/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSubarrayProductLessThanKv1(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int count = 0;
        while (left < n) {
            cout << left << ";" << right << endl;
            int tmp = 1;
            for (int i = left; i <= right; i++) {
                tmp *= nums[i];
            }
            if (tmp < k) {
                count++;
                right++;
            } else {
                left++;
                right = left;
            }
            if (right == n) {
                left++;
                right = left;
            }
        }
        return count;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {10, 5, 2, 6};
    Solution solve;
    int ret = solve.numSubarrayProductLessThanK(nums, 100);
    cout << ret << endl;
}