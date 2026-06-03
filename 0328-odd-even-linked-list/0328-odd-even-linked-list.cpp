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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* OddNode = new ListNode(-1);
        ListNode* EvenNode = new ListNode(-1);

        ListNode* temp1 = OddNode;
        ListNode* temp2 = EvenNode;

        ListNode* curr = head;

        long long count = 1;
        while(curr != NULL){
            if(count % 2 == 1){
                temp1 -> next = curr;
                temp1 = temp1 -> next;
            }
            else{
                temp2 ->next = curr;
                temp2 = temp2 -> next;
            }
            curr = curr -> next;
            count++;
        }
        temp2 -> next = nullptr;

        temp1 -> next = EvenNode -> next;
        return OddNode -> next;
    }
};