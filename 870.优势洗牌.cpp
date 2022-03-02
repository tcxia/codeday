/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end(), greater<int>()); // 从大到小排序

        vector<pair<int, int>> sorted2(n);
        for(int i = 0; i < n; i++){
            sorted2[i] = {nums2[i], i};
        }

        sort(sorted2.begin(), sorted2.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });

        vector<int> result(n);
        int left = 0, right = n - 1;
        for(int i = 0; i < n; i++){
            auto [cur, idx] = sorted2[i];
            if (nums1[left] <= cur){
                result[idx] = nums1[right];
                right--;
            }else{
                result[idx] = nums1[left];
                left++;
            }
        }
        return result;

    }
};
// @lc code=end

