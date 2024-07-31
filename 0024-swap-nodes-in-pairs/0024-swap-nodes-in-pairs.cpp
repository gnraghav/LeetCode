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
    ListNode* swapPairs(ListNode* head) {
            if (!head) {
                return NULL;
            }
           ListNode *prev = head;
           ListNode *curr = head->next; 
           ListNode *next;
            ListNode *temp;
           int count = 0;
           while (curr) {
                next = curr->next;
                curr->next = prev;
                prev->next = next;
                if (!count) {
                    head = curr;
                    temp = curr->next;
                } else if (count) {
                    temp->next = curr;
                    temp = curr->next;
                }
                if (next && next->next) {
                    prev = next;
                    curr = prev->next;
                } else {
                    break;
                }
                count ++;
           }
           return head;
    }
};