#include <iostream>
using namespace std;

class Solution {
    bool isSubString(string s1, string s2) {
        int i = 0;
        while (i < s1.size()) {
            string tstr = s1.substr(i, s2.size());
            // cout << tstr << endl;
            if (tstr.compare(s2) == 0) {
                return true;
            }
            i++;
        }
        return false;
    }

   public:
    int repeatedStringMatch(string a, string b) {
        if (isSubString(a, b)) {
            return 1;
        }
        int blen = b.size();
        int count = 1;
        int firstIndex = a.find(b[0]);
        if (firstIndex != string::npos) {
            while ((a.size() - firstIndex) <= blen) {
                a += a;
                count += 1;
                if (isSubString(a, b)) {
                    return count;
                }
            }
        }
        return -1;
    }
};

int main() {
    string a = "abcd";
    string b = "cdabcdab";
    Solution solve;
    int result = solve.repeatedStringMatch(a, b);
    cout << result << endl;
}