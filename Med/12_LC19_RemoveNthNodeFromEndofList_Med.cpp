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
        
        int count = 0;

        ListNode* current = head;

        while(current != nullptr){
            count++;
            current = current->next;
        }

        if(count == n){
            return head->next;
        }

        current = head;

        for(int i = 1; i < count- n; i++){
            current = current->next;
        }

        current ->next = current->next->next;

        return head;
    }
};
