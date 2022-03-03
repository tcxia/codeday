/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while (cur1 && cur2){
            if (cur1->val <= cur2->val){
                p->next = new ListNode(cur1->val);
                p = p->next;

                cur1 = cur1->next;
            }else{
                p->next = new ListNode(cur2->val);
                p = p->next;

                cur2 = cur2->next;
            }
        }

        while (cur1){
            p->next = new ListNode(cur1->val);
            p = p->next;
            cur1 = cur1->next;
        }

        while (cur2){
            p->next = new ListNode(cur2->val);
            p = p->next;
            cur2 = cur2->next;
        }

        return dummy->next;
    }
};
// @lc code=end
