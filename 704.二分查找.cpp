/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchv2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] > target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

