#include "../common/listNode.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        while (n-- && fast != nullptr) {
            fast = fast->next;
        }

        fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};