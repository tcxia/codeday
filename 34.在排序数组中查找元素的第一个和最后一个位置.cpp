/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

#include <vector>
#include <iostream>

using namespace std;
class Solution {
    int leftBoard(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int leftborder = -2;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target){
                // return mid;
                leftborder = mid;
                high = mid - 1;
            }else if (nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return leftborder;
    }

    int rightBoard(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int rightboard = -2;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target){
                // return mid;
                rightboard = mid;
                low = mid + 1;
            }else if (nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return rightboard;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rb = rightBoard(nums, target);
        int lb = leftBoard(nums, target);
        if (rb == -2 || lb == -2) return {-1, -1};
        else return {lb, rb};

    }
};
// @lc code=end

int main(){
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution solve;
    vector<int> ret = solve.searchRange(nums, 8);
    // cout << ret << endl;
    cout << ret[0] << endl;
    cout << ret[1] << endl;
}