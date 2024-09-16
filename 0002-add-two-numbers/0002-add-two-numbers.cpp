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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (!l1 && !l2) return NULL;

        int carry = 0, sum=0;
        ListNode* temp = new ListNode(0);
        ListNode* temp1 = temp;
        while(carry || l1 || l2) {
            sum = (l1?l1->val:0) + (l2?l2->val:0)+ carry;
            carry = sum/10;
            temp->next =new ListNode(sum%10);
            temp = temp->next;
            l1 = (l1 ? l1->next: NULL);
            l2 = (l2 ? l2->next: NULL);
        }
         
        //if (carry)  temp->next = new ListNode(carry);

        return temp1->next;
    }
};