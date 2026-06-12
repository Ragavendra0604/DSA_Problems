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
        ListNode* temp = head;
        int count = 0;

        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }

        int length = count - n + 1;
        
        if (length == 1) {
            ListNode* newHead = head->next;
        
            delete head; 
            return newHead;
        }
        
        ListNode* curr = head;
        for (int i = 1; i < length - 1; i++) {
            curr = curr->next;
        }

        ListNode* dummy = curr -> next;
        curr -> next = curr -> next -> next;
        delete dummy;
        
        return head;
    }
};