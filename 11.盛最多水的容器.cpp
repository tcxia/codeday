/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxAreav2(vector<int>& height) {
        int size = height.size();
        int max_area = INT32_MIN;
        int area = 0;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                if(height[i] <= height[j]){
                    area = height[i] * (j - i);
                }else{
                    area = height[j] * (j - i);
                }

                if (area > max_area){
                    max_area = area;
                }
            }
        }
        return max_area;
    }

    // 双指针
    int maxArea(vector<int>& height){
        int area = 0;
        int max_area = INT32_MIN;
        int left = 0;
        int right = height.size() - 1;
        while(left <= right){
            if(height[left] <= height[right]){
                area = (right - left) * height[left];
                left++;
            }else{
                area = (right - left) * height[right];
                right--;
            }

            if (area > max_area){
                max_area = area;
            }
        }
        return max_area;
    }
};
// @lc code=end

