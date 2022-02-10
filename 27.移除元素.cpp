/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeElementv2(vector<int>& nums, int val) {
        int flag = 0, point = 0;
        while(point < nums.size()){
            if(nums[point] == val){
                swap(nums[flag], nums[point]);
                flag++;
                point++;
            }else{
                point++;
            }
        }
        return point - flag;
    }

    int removeElement(vector<int>& nums, int val){
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if (val != nums[fastIndex]){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};
// @lc code=end
