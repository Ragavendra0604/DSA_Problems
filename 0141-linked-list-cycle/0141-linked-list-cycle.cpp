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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* Fast = head;
        ListNode* Slow = head;

        while(Fast && Fast -> next){
            Slow = Slow -> next;
            Fast = Fast -> next -> next;
            if(Fast == Slow){
                return true;
            }
        }
        return false;
    }
};