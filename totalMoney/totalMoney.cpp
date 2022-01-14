#include <iostream>
using namespace std;
class Solution {
   public:
    int totalMoney(int n) {
        // int head = n / 7
        // int tail = n % 7
        int head = n / 7; // 0
        int tail = n % 7; // 4
        int week = 1;
        int sum = 0;
        while (week <= head) {
            int sumtmp = 0;
            for (int i = week; i < week + 7; i++) {
                sumtmp += i;
            }
            week++;
            sum += sumtmp;
        }

        for(int i = head + 1; i < tail + head + 1; i++){
            sum += i;
        }
        
        return sum;
    }
};

int main() {
    Solution solve;
    int ret = solve.totalMoney(20);
    cout << ret << endl;
}