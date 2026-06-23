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
    ListNode* reverse(ListNode* head, ListNode* stop) {
        ListNode* prev = stop;
        ListNode* curr = head;
        while(curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k && temp != nullptr; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) return head;

        ListNode* kthNode = getKthNode(head, k);
        if (kthNode == nullptr) return head;

        ListNode* nextGroupHead = kthNode->next;

        ListNode* newHead = reverse(head, nextGroupHead);

        head->next = reverseKGroup(nextGroupHead, k);
        
        return newHead;
    }
};