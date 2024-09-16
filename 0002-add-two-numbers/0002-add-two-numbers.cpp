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
        while(l1 && l2) {
            sum = (l1->val + l2->val+ carry)%10;
            carry = (l1->val + l2->val+carry)/10;
            temp->next =new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
        }

        while (l2) {
            sum = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l2 = l2->next;
        }
         
        if (carry)  temp->next = new ListNode(carry);

        return temp1->next;
    }
};