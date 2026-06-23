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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(arr.begin(), arr.end());

        ListNode* t = head;
        for (size_t i = 0; t && i < arr.size(); ++i) {
            t->val = arr[i];
            t = t->next;
        }

        return head;
    }
};