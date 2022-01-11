#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    static constexpr int BLOCKED = -1;
    static constexpr int VALID = 0;
    static constexpr int FOUND = 1;

    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    static constexpr int BOUNDARY = 1000000;

   public:
    // bfs 广度优先遍历
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) {
            return true;
        }

        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o) -> size_t {
            // auto& [x, y] = o;
            auto& x = o.first;
            auto& y = o.second;
            return fn((long long)x << 20 | y);
        };

        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
        for (const auto& pos : blocked) {
            hash_blocked.emplace(pos[0], pos[1]);
        }

        auto check = [&](vector<int>& start, vector<int>& finish) -> int {
            int sx = start[0], sy = start[1];
            int fx = finish[0], fy = finish[1];
            int countdown = blocked.size() * (blocked.size() - 1) / 2;
            queue<pair<int, int>> q;
            q.emplace(sx, sy);
            unordered_set<pair<int, int>, decltype(hash_fn)> visited(0, hash_fn);
            visited.emplace(sx, sy);
            while (!q.empty() && countdown > 0) {
                // auto [x, y] = q.front();
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if (nx >= 0 && nx < BOUNDARY && ny >= 0 && ny < BOUNDARY && !hash_blocked.count({nx, ny}) && !visited.count({nx, ny})) {
                        if (nx == fx && ny == fy) {
                            return FOUND;
                        }
                        --countdown;
                        q.emplace(nx, ny);
                        visited.emplace(nx, ny);
                    }
                }
            }
            if (countdown > 0) {
                return BLOCKED;
            }
            return VALID;
        };
        int result = check(source, target);
        if (result == FOUND) {
            return true;
        } else if (result == BLOCKED) {
            return false;
        } else {
            result = check(target, source);
            if (result == BLOCKED) {
                return false;
            }
            return true;
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