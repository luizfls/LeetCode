/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;

        ListNode* fakeHead = new ListNode(); // will be removed in the end
        auto p = fakeHead;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else /* l2->val < l1->val */
            {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            }

            p = p->next;
        }
        while(l1 != nullptr)
        {
            p->next = new ListNode(l1->val);
            l1 = l1->next;
            p = p->next;
        }
        while(l2 != nullptr)
        {
            p->next = new ListNode(l2->val);
            l2 = l2->next;
            p = p->next;
        }

        p = fakeHead->next;
        delete fakeHead;
        return p;
    }
};
