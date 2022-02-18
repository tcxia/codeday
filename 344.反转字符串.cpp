/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    // void swapv1(int i, int j){
    //      int tmp = i;
    //      i = j;
    //      j = tmp;
    // }

    // void swapv2(int i, int j){
    //     i ^= j;
    //     j ^= i;
    //     i ^= j;
    // }


public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left <= right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

