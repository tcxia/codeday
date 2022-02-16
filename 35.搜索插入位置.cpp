/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // return nums[low] >= target ? low : (low + 1);
        return low;
    }
};
// @lc code=end


int main(){
    vector<int> nums = {1, 2, 3, 5};
    Solution solve;
    int ret = solve.searchInsert(nums, 6);
    cout << ret << endl;

}