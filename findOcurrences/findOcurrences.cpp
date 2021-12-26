#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<string> split(const string &str, const char *delim) {
        vector<string> res;
        int size = str.size();
        char *input = new char[size + 1];
        strcpy(input, str.c_str());
        char *token = strtok(input, delim);
        while (token != NULL) {
            res.push_back(token);
            token = strtok(NULL, delim);
        }
        delete[] input;
        return res;
    }

   public:
    vector<string> result;
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> temp = split(text, " ");
        for (int i = 0; i < temp.size() - 2; i++) {
            if (temp[i] == first && temp[i + 1] == second) {
                result.push_back(temp[i + 2]);
            }
        }
        return result;
    }
};

int main() {
    Solution solve;
    string text = "we will we will rock you";
    string first = "we";
    string second = "will";
    vector<string> result = solve.findOcurrences(text, first, second);
    for (auto &res : result) {
        cout << res << ",";
    }
}