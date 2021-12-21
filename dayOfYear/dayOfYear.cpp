#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool twoMonth(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;
        } else {
            return false;
        }
    }

    vector<string> split(const string& str, const string& delim) {  //将分割后的子字符串存储在vector中
        vector<string> res;
        if ("" == str) return res;

        string strs = str + delim;  //*****扩展字符串以方便检索最后一个分隔出的字符串
        size_t pos;
        size_t size = strs.size();

        for (int i = 0; i < size; ++i) {
            pos = strs.find(delim, i);               // pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
            if (pos < size) {                        //如果查找到，如果没有查找到分隔符，pos为string::npos
                string s = strs.substr(i, pos - i);  //*****从i开始长度为pos-i的子字符串
                res.push_back(s);                    //两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
                i = pos + delim.size() - 1;
            }
        }
        return res;
    }

    map<int, int> monthDay = {
        {1, 31},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };

   public:
    int dayOfYear(string date) {
        int days = 0;

        vector<string> result = split(date, "-");
        int year = stoi(result[0]);
        if (twoMonth(year)) {
            monthDay.insert(make_pair(2, 29));
        } else {
            monthDay.insert(make_pair(2, 28));
        }
        int month = stoi(result[1]);
        int day = stoi(result[2]);

        for (int i = 1; i < month; i++) {
            days += monthDay[i];
        }
        days += day;
        return days;
    }
};

int main() {
    Solution s;
    int result = s.dayOfYear("2019-01-09");
    cout << result << endl;
}