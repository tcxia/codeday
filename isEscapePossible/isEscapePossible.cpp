#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    static constexpr int BLOCKED = -1;
    static constexpr int VALID = 0;
    static constexpr int FOUND = 1;

    static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    static constexpr int BOUNDARY = 1000000;

   public:
    // bfs 广度优先遍历
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) {
            return true;
        }

        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o) -> size_t {
            auto& [x, y] = o;
            return fn((long long)x << 20 | y);
        };

        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
        for (const auto& pos : blocked) {
            hash_blocked.emplace(pos[0], pos[1]);
        }
    }
};

int main() {
    vector<vector<int>> blocked = {{0, 1}, {1, 0}};
    vector<int> source = {0, 0};
    vector<int> target = {0, 2};
    Solution solve;
    bool ret = solve.isEscapePossible(blocked, source, target);
    cout << ret << endl;
}