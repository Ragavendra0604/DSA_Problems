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
    ListNode* lastNode(ListNode* head, int k){
        int cnt = 1;
        ListNode* temp = head;

        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp -> next;
        }

        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        int length = 1;

        ListNode* tail = head;
        ListNode* temp = head;

        while(tail -> next != NULL){
            tail = tail -> next;
            length++;
        }

        if(k % length == 0) return head;

        k = k % length;

        tail -> next = head;

        ListNode* NewLastNode = lastNode(head, length - k);

        head = NewLastNode -> next;
        NewLastNode -> next = nullptr;

        return head;
    }
};