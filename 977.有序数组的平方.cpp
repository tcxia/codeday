/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquaresv2(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            result.push_back(nums[i] * nums[i]);
        }

        sort(result.begin(), result.end());

        return result;
    }


    vector<int> sortedSquares(vector<int>& nums){
        vector<int> result;

        // if (nums.size() == 1){
        //     result.push_back(nums[0] * nums[0]);
        //     return result;
        // }
        if (nums[nums.size() - 1] < 0){
            // result.push_back(nums[])
            for(int i = nums.size() - 1; i >= 0; i--){
                result.push_back(nums[i] * nums[i]);
            }
            return result;
        }


        int pointA = 0, pointB = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0){
                pointA = i;
                pointB = i - 1;
                break;
            }
        }

        while (pointB >= 0 && pointA < nums.size()){
            if ((-1) * nums[pointB] > nums[pointA]){
                result.push_back(nums[pointA] * nums[pointA]);
                pointA++;
            }else{
                result.push_back(nums[pointB] * nums[pointB]);
                pointB--;
            }
        }
        while (pointB >= 0){
            result.push_back(nums[pointB] * nums[pointB]);
            pointB--;
        }
        
        while (pointA < nums.size()){
            result.push_back(nums[pointA] * nums[pointA]);
            pointA++;
        }

        return result;
    }
};
// @lc code=end

