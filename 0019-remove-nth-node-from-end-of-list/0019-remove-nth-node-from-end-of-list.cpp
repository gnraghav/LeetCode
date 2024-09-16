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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;

        ListNode* first = head;
        ListNode* last = head;
        while(n) {
            last=last->next;
            n--;
        }
        if(!last) return head->next;
        while(last->next) {
            first=first->next;
            last=last->next;
        }
        first->next = first->next->next;
        return head;
    }
};