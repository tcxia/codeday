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
        int low = 0, high = x;
        int res = -1;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (mid * mid <= x){
                res = mid;
                low = mid + 1;
            }else if (mid * mid > x){
                high = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution solve;
    int ret = solve.mySqrt(8);
    cout << ret << endl;
}

