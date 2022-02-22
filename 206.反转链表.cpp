/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
   // 双指针
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            temp = cur->next; // 保存下一个节点
            cur->next = pre; // 反转操作
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    // 递归写法
    ListNode* reverseListv2(ListNode* head){
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur){
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        return reverse(cur, tmp);
    }
};
// @lc code=end
