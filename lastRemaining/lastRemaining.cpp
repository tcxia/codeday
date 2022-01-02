#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lastRemaining(int n) {
        if(n == 1){
            return 1;
        }

        if(n % 2 == 1){
            return lastRemaining(n - 1);
        }

        return n + 2 - 2 * lastRemaining(n / 2);
        
    }
};

int main() {
    Solution solve;
    int result = solve.lastRemaining(9);
    cout << result << endl;
}