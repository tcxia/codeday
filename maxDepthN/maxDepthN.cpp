#include <vector>

#include <queue>

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    int count = 0;

   public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            count++;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                for (int i = 0; i < node->children.size(); i++) {
                    que.push(node->children[i]);
                }
            }
        }
        return count;
    }
};