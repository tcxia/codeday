/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size()-1);
        int start = 0;
        int end = 0;
        bool entry = false;
        for(int i = 0; i < s.size(); i++){
            if (!entry){
                start = i;
                entry = true;
            }
            if (entry && s[i] == ' ' && s[i-1] != ' '){
                end = i - 1;
                entry = false;
                reverse(s, start, end);
            }
            if (entry && (i == (s.size() - 1)) && s[i] != ' '){
                end = i;
                entry = false;
                reverse(s, start, end);
            }
        }
        return s;
    }

    void removeExtraSpaces(string &s){
        int slowIndex = 0, fastIndex = 0;
        while(s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' '){
            fastIndex++;
        }
        for(; fastIndex < s.size(); fastIndex++){
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') continue;
            else s[slowIndex++] = s[fastIndex];
        }

        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') s.resize(slowIndex - 1);
        else s.resize(slowIndex);
    }

    void reverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
// @lc code=end

int main(){
    string s = "  hello world";
    Solution solve;
    solve.reverseWords(s);
}