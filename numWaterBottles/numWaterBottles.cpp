#include <iostream>
using namespace std;

class numWaterBottles {
   public:
    int waterbottle(int numBottles, int numExchange) {
        int total = numBottles;
        int a = numBottles / numExchange;
        total += a;
        int b = numBottles % numExchange;
        int temp = a + b;
        while (temp >= numExchange) {
            int c = temp / numExchange;
            total += c;
            int d = temp % numExchange;
            temp = c + d;
        }
        return total;
    }
};

int main() {
    numWaterBottles nwb;
    int res = nwb.waterbottle(9, 3);
    cout << "total Botteles: " << res << endl;
}