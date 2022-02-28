/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start

#include <iostream>


using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int point_s = 0;
        for(int i = 0; i < t.size(); i++){
            if (t[i] == s[point_s]){
                point_s++;
            }
        }
        if (point_s == s.size()){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end

