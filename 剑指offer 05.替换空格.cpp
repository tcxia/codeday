/**
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
*/


#include <iostream>


using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == ' ') count++;
        }

        int newlen = s.size() + count * 2;
        int pointold = s.size() - 1;
        int pointnew = newlen - 1;
        
        s.resize(newlen); //  重新初始化

        while(pointold > 0){
            if (s[pointold] != ' '){
                s[pointnew] = s[pointold];
            }else{
                s[pointnew] = '0';
                s[pointnew - 1] = '2';
                s[pointnew - 2] = '%';
                pointnew -= 2;
            }
            pointold--;
            pointnew--;
        }
        return s;
    }
};

int main(){
    string a = "we are happy";
    Solution solve;
    string ret = solve.replaceSpace(a);
    cout << ret << endl;
}