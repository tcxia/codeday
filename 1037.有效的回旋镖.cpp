/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isLine(vector<int> a, vector<int> b, vector<int> c) {
        if (b[0] == a[0]) {
            if (b[0] != c[0]) {
                return true;
            } else {
                return false;
            }
        } else {
            float k = (b[1] - a[1]) / (b[0]*1.0 - a[0]); // 当除数和被除数都是整型时，即使结果定义为float，输出结果仍然是整数
            if ((c[1] - a[1]) == k * (c[0] - a[0])) {
                return false;
            } else {
                return true;
            }
        }
    }

    bool isSame(vector<int> a, vector<int> b, vector<int> c) {
        if ((a[0] == b[0] && a[1] == b[1]) || (a[0] == c[0] && a[1] == c[1]) || (b[0] == c[0] && b[1] == c[1]))
            return false;
        else
            return true;
    }
    bool isBoomerang(vector<vector<int>>& points) {
        // cout << isLine(points[0], points[1], points[2]) << endl;
        // cout << isSame(points[0], points[1], points[2]) << endl;
        if (isLine(points[0], points[1], points[2]) && isSame(points[0], points[1], points[2])) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end