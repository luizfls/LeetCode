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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        auto p = head;
        auto q = head->next;
        auto r = head->next->next;
        auto s = head->next->next->next;

        while(r != nullptr)
        {
            auto tmp = p->next;
            p->next = r;
            r->next = tmp;
            q->next = s;

            p = r;
            q = s;
            r = s != nullptr ? s->next : nullptr;
            s = r != nullptr ? r->next : nullptr;
        }

        return head;
    }
};
