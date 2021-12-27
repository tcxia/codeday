#include <queue>
#include <vector>
#include <iostream>
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
    vector<vector<int>> result;

   public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                temp.push_back(node->val);
                int subsize = node->children.size();
                if (subsize > 0) {
                    for (int i = 0; i < subsize; i++) {
                        que.push(node->children[i]);
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Node* p1 = new Node(1);
    Node* p2 = new Node(2);
    Node* p3 = new Node(3);
    Node* p4 = new Node(4);
    Node* p5 = new Node(5);
    Node* p6 = new Node(6);
    Node* p7 = new Node(7);
    Node* p8 = new Node(8);
    Node* p9 = new Node(9);
    Node* p10 = new Node(10);
    Node* p11 = new Node(11);
    Node* p12 = new Node(12);
    Node* p13 = new Node(13);
    Node* p14 = new Node(14);

    p1->children.push_back(p2);
    p1->children.push_back(p3);
    p1->children.push_back(p4);
    p1->children.push_back(p5);

    p3->children.push_back(p6);
    p3->children.push_back(p7);

    p4->children.push_back(p8);

    p5->children.push_back(p9);
    p5->children.push_back(p10);

    p7->children.push_back(p11);
    p8->children.push_back(p12);
    p9->children.push_back(p13);

    p11->children.push_back(p14);

    Node* root = p1;

    Solution solve;
    vector<vector<int>> result;
    result = solve.levelOrder(root);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ",";
        }
        cout << endl;
    }
}