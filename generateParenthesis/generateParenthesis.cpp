#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> result;
    string s;

    bool isValid(string sub) {
        stack<char> st;
        for (int i = 0; i < sub.size(); i++) {
            if (sub[i] == '(')
                st.push(sub[i]);
            else {
                st.pop();
            }
        }
        if (!st.empty()) {
            return false;
        } else {
            return true;
        }
    }

    void backtracking(string& sl, int n, int startIndex) {
        if (s.size() == 2 * n && isValid(s)) {
            result.push_back(s);
            return;
        }

        for (int i = startIndex; i < sl.size(); i++) {
            s.push_back(sl[i]);
            backtracking(sl, n, i + 1);
            s.pop_back();
        }
    }


    void backtrackingv2(vector<string>& ans, string& cur, int open, int close, int n){
        if (cur.size() == n *  2){
            ans.push_back(cur);
            return;
        }

        if (open < n){ // 如果左括号数量不大于n，可以放一个左括号
            cur.push_back('(');
            backtrackingv2(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        
        if (close < open){ // 如果右括号数量小于左括号的数量，可以放置右括号
            cur.push_back(')');
            backtrackingv2(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        string stmp;
        string left = "(";
        string right = ")";

        for (int i = 0; i < n; i++) {
            stmp += left;
            stmp += right;
        }
        result.clear();
        s.clear();

        backtracking(stmp, n, 0);

        return result;
    }


    vector<string> generateParenthesisv2(int n){
        vector<string> result;
        string current;
        backtrackingv2(result, current, 0, 0, n);
        return result;
    }
};

int main() {
    Solution solve;
    vector<string> ret = solve.generateParenthesis(3);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}