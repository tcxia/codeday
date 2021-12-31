#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> result;
    vector<int> countFactor(int num) {
        vector<int> temp;
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                temp.push_back(i);
            }
        }
        return temp;
    }

    vector<int> countFactorv2(int num) {
        vector<int> temp;
        for (int d = 2; d * d <= num; ++d) {
            if (num % d == 0) {
                temp.push_back(d);
                temp.push_back(num / d);
            }
        }
        return temp;
    }

   public:
    bool checkPerfectNumber(int num) {
        result = countFactor(num);
        int sum = 0;
        for (int i = 0; i < result.size(); i++) {
            sum += result[i];
        }
        if (sum == num) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solve;
    bool flag = solve.checkPerfectNumber(8128);
    cout << flag << endl;
}