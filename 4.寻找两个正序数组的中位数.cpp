/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int> result;

        int a = 0;
        int b = 0;
        int point = 0;
        while (a < m && b < n) {
            if (nums1[a] <= nums2[b]) {
                result[point++] = nums1[a++];
            } else {
                result[point++] = nums2[b++];
            }
        }

        while (a < m) {
            result[point++] = nums1[a++];
        }

        while (b < n) {
            result[point++] = nums2[b++];
        }
        // for (int i = 0; i < result.size(); i++) {
        //     cout << result[i] << endl;
        // }
        int total = m + n;
        if (total % 2 == 0) {
            return (double)(result[total / 2] + result[total / 2 - 1]) / 2;
        } else {
            return result[(total - 1) / 2];
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution solve;
    double ret = solve.findMedianSortedArrays(nums1, nums2);
    cout << ret << endl;
}