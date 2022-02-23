/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
   public:
    bool isVilad(char c){
        if ((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z')){
            return true;
        }else{
            return false;
        }
    }

    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right){
            if (isVilad(s[left]) && isVilad(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }else if (isVilad(s[left]) && !isVilad(s[right])){
                right--;
            }else if (!isVilad(s[left]) && isVilad(s[right])){
                left++;
            }else if (!isVilad(s[left]) && !isVilad(s[right])){
                left++;
                right--;
            }
        }
        return s;
    }
};
// @lc code=end
