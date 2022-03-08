/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

   public:
    bool isPalindrome(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast){
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast){
            slow = slow->next;
        }

        ListNode *left = head;
        ListNode *right = reverseList(slow);

        while (right){
            if (left->val != right->val){
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};
// @lc code=end
