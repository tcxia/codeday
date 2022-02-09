/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSumv2(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if (nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }

    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]); // 查找元素
            if (iter != map.end()){  //  判断是否在unordered_map里
                return {iter->second, i};
            }
            map.insert(pair<int, int>{nums[i], i}); // 添加元素到map里
        }
        return {};
    }
};
// @lc code=end

