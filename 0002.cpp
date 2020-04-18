/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* last = dummy;
        bool carry = false;

        while(l1 != nullptr && l2 != nullptr)
        {
            int digit = l1->val + l2->val + (carry ? 1 : 0);
            carry = digit >= 10;
            last->next = new ListNode(digit % 10);
            last = last->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr)
        {
            int digit = l1->val + (carry ? 1 : 0);
            carry = digit >= 10;
            last->next = new ListNode(digit % 10);
            last = last->next;
            l1 = l1->next;
        }

        while(l2 != nullptr)
        {
            int digit = l2->val + (carry ? 1 : 0);
            carry = digit >= 10;
            last->next = new ListNode(digit % 10);
            last = last->next;
            l2 = l2->next;
        }

        if(carry)
            last->next = new ListNode(1);

        ListNode* sum = dummy->next;
        delete dummy;
        return sum;
    }
};
