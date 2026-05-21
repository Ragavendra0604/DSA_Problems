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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedLL = reverseLL(head);
        ListNode* curr = reversedLL;
        int maxSeen = curr -> val;
        while(curr -> next){
            if(curr -> next -> val < maxSeen){
                curr -> next = curr -> next -> next;
            }
            else{
                curr = curr -> next;
                maxSeen = curr -> val;
            }
        }
        return reverseLL(reversedLL);
    }
};