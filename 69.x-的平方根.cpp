/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int low = 1, high = x;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (mid == x / mid){  // 不能使用mid * mid 和 x比较，比较 mid 和 x/mid
                return mid;
            }else {
                if (mid < x / mid){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return high;
    }
};
// @lc code=end

int main(){
    Solution solve;
    int ret = solve.mySqrt(8);
    cout << ret << endl;
}

