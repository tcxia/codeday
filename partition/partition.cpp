#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()){
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }

            backtracking(s, i + 1);

            path.pop_back();
        }
    }

    bool isPalindrome(const string&  str, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--){
            if(str[i] != str[j]){
                return false;
            }
        }
        return true;
    }

   public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        // vector<bool> used(s.size(), false);

        backtracking(s, 0);
        return result;
    }
};

int main() {
    string s = "aab";
    Solution solve;
    vector<vector<string>> result;
    result = solve.partition(s);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}