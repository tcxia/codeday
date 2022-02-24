/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int compute(int &a, int &b, string op) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else if (op == "*") {
            return a * b;
        } else {
            return a / b;
        }
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = compute(b, a, tokens[i]);
                st.push(temp);
            } else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
// @lc code=end

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution solve;
    int ret = solve.evalRPN(tokens);
    cout << ret << endl;
}