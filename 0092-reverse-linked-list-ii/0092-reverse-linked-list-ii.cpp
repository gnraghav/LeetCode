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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        // Initialize pointers
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 1;

        // Move curr to the left position
        while (count < left) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // Reverse the sublist between left and right
        ListNode* sublistPrev = prev; // Points to the node before the sublist
        ListNode* sublistEnd = curr; // Points to the node at the right position

        while (count <= right) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Connect the reversed sublist back to the main list
        if (sublistPrev) {
            sublistPrev->next = prev;
        } else {
            // If left position is the head, update head
            head = prev;
        }
        sublistEnd->next = curr;

        return head;
    }
};