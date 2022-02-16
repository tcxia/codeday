/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start

#include <vector>
#include <iostream>

using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int point = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != nums[point]){
                nums[point+1] = nums[i];
                point++;
            }
        }
        return point + 1;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 1, 2};
    Solution solve;
    int ret = solve.removeDuplicates(nums);
    cout << ret << endl;
}