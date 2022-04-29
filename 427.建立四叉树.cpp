/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
   public:
    bool isLeaf(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        int init = grid[x1][y1];
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                if (grid[x][y] != init) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* constructNode(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        if (isLeaf(grid, x1, y1, x2, y2)) {
            return new Node(grid[x1][y1] == 1, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            int xMid = (x1 + x2) / 2;
            int yMid = (y1 + y2) / 2;

            Node* topLeft = constructNode(grid, x1, y1, xMid, yMid);
            Node* bottomLeft = constructNode(grid, xMid, y1, x2, yMid);
            Node* topRight = constructNode(grid, x1, yMid, xMid, y2);
            Node* bottomRight = constructNode(grid, xMid, yMid, x2, y2);

            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        return constructNode(grid, 0, 0, grid[0].size(), grid.size());
    }
};
// @lc code=end
