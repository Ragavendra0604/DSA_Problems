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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return nullptr;

        int count1 = 0, count2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1){
            count1++;
            temp1 = temp1 -> next;
        }
        
        while(temp2){
            count2++;
            temp2 = temp2 -> next;
        }

        int d = abs(count1 - count2);
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        if(count1 > count2){
            for(int i = 0 ; i < d ; i++) ptr1 = ptr1 -> next;
        }else{
            for(int i = 0 ; i < d ; i++) ptr2 = ptr2 -> next;
        }

        while(ptr1 && ptr2){
            if(ptr1 == ptr2){
                return ptr1;
            }
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        return nullptr;
    }    
};