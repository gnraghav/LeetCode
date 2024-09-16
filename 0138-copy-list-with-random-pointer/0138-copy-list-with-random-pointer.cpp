/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // <given Node, newNode>
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        // To store a new copy node
        while(temp) {
            mp[temp] = new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
    }
};