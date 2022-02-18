/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> map;
        for(int i = 0; i < t.size(); i++){
            map[t[i]]++;
        }
        int left = 0;
        int len = INT32_MAX;
        int count = 0;
        string result = "";

        for(int i = 0; i < s.size(); i++){
            if (map.find(s[i]) != map.end()){
                map[s[i]]--;

                if (map[s[i]] >= 0) count++; // 若字符还是大于0，则字符至少存在2个

                while (count == t.size()){ // 若count == t，则代表找到t中所有元素了
                    if (i - left + 1 < len){ // 判断长度
                        len = i - left + 1;
                        result = s.substr(left, len);
                    }
                    if (map.find(s[left]) != map.end()){ // 若map中存在窗口的左边界元素，说明移除了一个t中的组成元素
                        map[s[left]]++; // 则对应数量 + 1
                        if (map[s[left]] > 0) count--; // 如果数量大于0，则count - 1
                    }
                    left++; // 子窗口左移动
                }
            }
        }
        return result;
    }
};
// @lc code=end

