/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int singleNonDuplicatev2(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }
        for(auto iter = counts.begin(); iter != counts.end(); ++iter){
            if (iter->second == 1){
                return iter->first;
            }
        }
        return 0;
    }

    int singleNonDuplicate(vector<int>& nums){
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid ^ 1]){ // mid 左右个数为奇数和偶数来判断
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return nums[low];
    }
};
// @lc code=end

