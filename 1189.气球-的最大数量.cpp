/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// balloon

class Solution {
public:
    vector<char> result;
    unordered_map<int, int> map;
    int count = 0;
    int maxNumberOfBalloons(string text) {
        for(int i = 0; i < text.size(); i++){
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n'){
                result.push_back(text[i]);
            }
            // string s = "";
        }

        if (result.size() < 7) return 0;

        for(int i = 0; i < result.size(); i++){
            map[result[i]]++;
        }
        
        while (map['b'] == 1 && map['a'] == 1 && map['l'] == 2 && map['o'] == 2 && map['n'] == 1){
            count++;
            map['b']--;
            map['a']--;
            map['l'] = map['l'] - 2;
            map['o'] = map['o'] - 2;
            map['n']--;
        }

        return count;
    }
};
// @lc code=end

