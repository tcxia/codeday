/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 *
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    // pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
    //     ListNode* prev = tail->next;
    //     ListNode* p = head;

    //     while (prev != tail) {
    //         ListNode* nex = p->next;
    //         p->next = prev;
    //         prev = p;
    //         p = nex;
    //     }

    //     return {head, tail};
    // }

    void reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;

        for(int i = 0; i < left - 1; i++){
            pre = pre->next;
        }

        ListNode* rightNode = pre;
        for(int i = 0; i < right - left + 1; i++){
            rightNode = rightNode->next;
        }

        ListNode* leftNode = pre->next;
        ListNode* cur = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseList(leftNode);

        pre->next = rightNode;
        leftNode->next = cur;
    


        return dummy->next;
    }
};
// @lc code=end
