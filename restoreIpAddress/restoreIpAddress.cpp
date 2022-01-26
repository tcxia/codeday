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


    vector<string> resultv2; // 记录结果

    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValidv2(const string& s, int start, int end){
        if (start > end){
            return false;
        }

        if (s[start] == '0' && start != end){ // 0开头的数字不合法
            return false;
        }

        int num = 0;
        for(int i = start; i <= end; i++){
            if (s[i] > '9' || s[i] < '0'){  // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255){   // 如果大于255 不合法
                return false;
            }
        }
        return true;
    }
// startIndex: 搜索的起始位置, pointNum: 添加逗点的数量
    void backtrackingv2(string& s, int startIndex, int pointNum){
        if (pointNum == 3){ // 逗点数量为3时，分隔结束
            // 判断第四子字符串是否合法，如果合法就放进result中
            if (isValidv2(s, startIndex, s.size() - 1)){
                resultv2.push_back(s);
            }
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if (isValidv2(s, startIndex, i)){ // 判断 [startIndex, i]这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum++;
                backtrackingv2(s, i + 2, pointNum); // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;  // 回溯
                s.erase(s.begin() + i + 1); // 回溯删掉逗点
            }else break; // 不合法，直接结束本层循环
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