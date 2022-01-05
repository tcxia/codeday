#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<char> alphabet = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

   public:
    string modifyString(string s) {
        // 将string 转vector<char>
        vector<char> ret;
        for (int i = 0; i < s.size(); i++) {
            ret.push_back(s.at(i));
        }
        // 判断"?"出现的位置
        // 1. 最左边
        if (ret[0] == '?') {
            for (int i = 0; i < alphabet.size(); i++) {
                if (alphabet[i] == ret[1] && ret[1] != '?') {
                    vector<char>::iterator it = alphabet.begin() + i;
                    alphabet.erase(it);
                }
            }
            ret[0] = alphabet[rand() % 25];
        }
        // 2. 最右边
        // if (s.at(s.size() - 1) == '?') {
        //     s.at(s.size() - 1) = alphabet[rand() % 26];
        // }
        // // 3. 中间
        // for (int i = 1; i < s.size() - 1; i++) {
        //     if (s.at(i) == '?') {
        //         s.at(i) = alphabet[rand() % 26];
        //     }
        // }
        cout << alphabet.size() << endl;
        string ret_string;
        ret_string = accumulate(ret.begin(), ret.end(), ret_string);

        return ret_string;
    }
};

int main() {
    Solution solve;
    string ret = solve.modifyString("?abcd");
    cout << ret << endl;
}