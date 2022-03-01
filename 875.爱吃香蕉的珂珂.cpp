/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {

    // 定义: 速度为x时，需要f(x)小时吃完所有香蕉
    // f(x)随着x的增加单调递减
    int f(vector<int>& piles, int x){
        int hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += piles[i] / x;
            if (piles[i] % x > 0){
                hours++;
            }
        }
        return hours;
    }
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT32_MAX;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
