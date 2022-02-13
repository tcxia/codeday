/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// balloon

class Solution {
public:
    vector<char> result;
    unordered_map<int, int> map;
    int count = INT32_MAX;
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
            // cout << result[i] << endl;
        }

        // if (map['l'] == map['o'] && map['l'] - map['b'] == 1 && map['b'] == map['a'] && map['a'] == map['n']){
        //     count++;
        // } 
        map['l'] /= 2;
        map['o'] /= 2;

        // return *min_element(map.begin(), map.end());


    //     for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
    //     cout << "<" << iter->first << ", " << iter->second << ">" << endl;
    // }
        for(auto iter = map.begin(); iter != map.end(); ++iter){
            count = iter->second < count ? iter->second : count;
        }
        return count;
    }
};
// @lc code=end

int main(){
    string text = "loonbalxballpoon";
    Solution solve;
    int ret = solve.maxNumberOfBalloons(text);
    cout << ret << endl;
}