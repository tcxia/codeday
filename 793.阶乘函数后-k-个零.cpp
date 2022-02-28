/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start

#include <iostream>
#include <climits>

using namespace std;

class Solution {

    long trailingZeros(long n){
        long res = 0;
        for(long d = n; d / 5 > 0; d = d / 5){
            res += d / 5;
        }
        return res;
    }

    // 搜索trailingZeros(n) == K的左边界
    long leftBound(int target){
        long low = 0, high = LONG_MAX;
        while (low < high){
            long mid = low + (high - low) / 2;
            if (trailingZeros(mid) < target){
                low = mid + 1;
            }else if (trailingZeros(mid) > target){
                high = mid;
            }else{
                high = mid;
            }
        }
        return low;
    }

    // 搜索trailingZeros(n) == K的右边界
    long rightBound(int target){
        long low = 0, high = LONG_MAX;
        while (low < high){
            long mid = low + (high - low) / 2;
            if (trailingZeros(mid) < target){
                low = mid + 1;
            }else if (trailingZeros(mid) > target){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low - 1;
    }

public:
    int preimageSizeFZF(int k) {
        return (int)(rightBound(k) - leftBound(k) + 1); // 左边界和右边界之差 + 1就是答案
    }
};
// @lc code=end

