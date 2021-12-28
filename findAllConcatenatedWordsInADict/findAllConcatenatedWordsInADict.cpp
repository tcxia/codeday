#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<string> result;
    vector<string> path;

    string joinString(vector<string>& path) {
        string str;
        for (int i = 0; i < path.size(); i++) {
            str += path[i];
        }
        return str;
    }

    void backtracking(vector<string>& words, string strs) {
        if (path.size() > 1) {
            if (find(words.begin(), words.end(), strs) != words.end()) {
                result.push_back(strs);
            }
        }

        for (int i = 0; i < words.size(); i++) {
            path.push_back(words[i]);
            string newstr = joinString(path);
            backtracking(words, newstr);

            path.pop_back();
        }
    }

   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        result.clear();
        path.clear();
        string initStr;
        backtracking(words, initStr);
        return result;
    }
};

int main() {
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    Solution solve;
    vector<string> result;
    result = solve.findAllConcatenatedWordsInADict(words);
    for (auto& res : result) {
        cout << res << endl;
    }
}