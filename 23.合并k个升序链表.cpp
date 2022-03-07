/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

#include <vector>

using namespace std;

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        ListNode* cur0 = p1;
        ListNode* cur1 = p2;

        while (cur0 && cur1) {
            if (cur0->val <= cur1->val) {
                p->next = new ListNode(cur0->val);
                cur0 = cur0->next;
            } else {
                p->next = new ListNode(cur1->val);
                cur1 = cur1->next;
            }
            p = p->next;
        }

        while (cur0) {
            p->next = new ListNode(cur0->val);
            p = p->next;
            cur0 = cur0->next;
        }

        while (cur1) {
            p->next = new ListNode(cur1->val);
            p = p->next;
            cur1 = cur1->next;
        }

        return dummy->next;
    }


    ListNode* mergeTwoListsv2(ListNode* p1, ListNode* p2){
        if ((!p1) || (!p2)) return p1 ? p1 : p2; 
        ListNode head;
        ListNode *tail = &head;
        ListNode *p1Ptr = p1;
        ListNode *p2Ptr = p2;


        while (p1Ptr && p2Ptr){
            if (p1Ptr->val < p2Ptr->val){
                tail->next = p1Ptr;
                p1Ptr = p1Ptr->next;
            }else{
                tail->next = p2Ptr;
                p2Ptr = p2Ptr->next;
            }
            tail = tail->next;
        }
        tail->next = (p1Ptr ? p1Ptr : p2Ptr);
        return head.next;
    }


   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int flag = 0;
        ListNode* result = nullptr;
        while (flag < n) {
            result = mergeTwoListsv2(result, lists[flag]);
            flag++;
        }

        return result;
    }
};
// @lc code=end
