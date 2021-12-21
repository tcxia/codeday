#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> result;
    vector<string> path;

    vector<string> convert_result;

    bool isValid(const string& str) {
        if (((str.size() > 1) && str[0] == '0') || str.size() > 3) {
            return false;
        }

        int ipnum = stoi(str); // 字符串转整型
        // cout << ipnum << endl;
        if (ipnum >= 0 && ipnum <= 255) {
            return true;
        }
        return false;
    }

    void backtracking(const string& str, int startIndex, vector<string>& path, int sumstr) {
        if (path.size() == 4) {
            for (int i = 0; i < path.size(); i++) {
                sumstr += path[i].size();
                if (sumstr == str.size()) {
                    result.push_back(path);
                    return;
                }
            }
        }

        for (int i = startIndex; i < str.size(); i++) {
            string ipstr = str.substr(startIndex, i - startIndex + 1); // 截取字符串，第一个参数截取起始pos，第二个参数截取len
            if (isValid(ipstr)) {
                path.push_back(ipstr);
            } else {
                continue;
            }

            backtracking(str, i + 1, path, sumstr);
            path.pop_back();
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        path.clear();

        backtracking(s, 0, path, 0);

        for (auto& res : result) {
            stringstream ss;
            string ip;
            copy(res.begin(), res.end(), ostream_iterator<string>(ss, ".")); // 拼接字符串
            ip = ss.str();
            convert_result.push_back(ip.substr(0, ip.size() - 1));
        }

        return convert_result;
    }
};

int main() {
    string s = "101023";
    Solution solve;
    vector<string> result;
    result = solve.restoreIpAddresses(s);
    for (auto& res : result) {
        cout << res << endl;
    }
}