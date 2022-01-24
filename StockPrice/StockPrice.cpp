#include <unordered_map>
using namespace std;

class StockPrice {
    unordered_map<int, int> m_price;
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        m_price[timestamp] = price;
    }
    
    int current() {
        return m_price[m_price.size()-1];
    }
    
    int maximum() {
        
    }
    
    int minimum() {

    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */