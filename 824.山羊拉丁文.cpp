/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        vector<char> pattern = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        string delim = " ";
        sentence.append(delim);
        size_t pos = sentence.find(" ");
        while (pos != sentence.npos) {
            string temp = sentence.substr(0, pos);
            words.push_back(temp);

            sentence = sentence.substr(pos + 1, sentence.size());
            pos = sentence.find(" ");
        }

        for (int i = 0; i < words.size(); i++) {
            char temp = words[i].at(0);

            // 不是元音
            if (find(pattern.begin(), pattern.end(), temp) == pattern.end()) {
                words[i].erase(0, 1);
                words[i] = words[i] + temp;
                words[i].append("ma");

            }
            // 是元音
            else {
                words[i].append("ma");
            }
            int n = 0;
            while (n < i + 1) {
                words[i].append("a");
                n++;
            }
        }

        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            result += " ";
        }
        // result = result.substr(0, result.size() - 1); // 删除最后一个元素
        result.erase(result.size() - 1);
        return result;
    }
};
// @lc code=end

int main() {
    string context = "I speak Goat Latio";
    Solution solve;
    string ret = solve.toGoatLatin(context);
    cout << ret << endl;
}
