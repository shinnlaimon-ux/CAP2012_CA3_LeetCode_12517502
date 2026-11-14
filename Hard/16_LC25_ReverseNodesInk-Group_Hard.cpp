#include <iostream>
using namespace std;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1){
            return head;
        }

        ListNode* current = head;
        ListNode* newHead = nullptr;
        ListNode* prvEnd = nullptr;

        while(current != nullptr){
            ListNode* end = current;

            for (int i = 1; i< k && end != nullptr; i++){
                end = end->next;
            }

            if(end == nullptr){
                break;
            }

            ListNode* next = end->next;
            ListNode* prev = next;
            ListNode* temp = current;

            while(temp != next){
                ListNode* save = temp->next;

                temp->next = prev;

                prev = temp;
                temp = save;
            }

            if(newHead == nullptr){
                newHead = end;
            }

            if(prvEnd != nullptr){
                prvEnd->next = end;
            }
            prvEnd = current;
            current = next;
        }
        
        if(newHead == nullptr){
            return head;
        }
        else{
            return newHead;
        }
    }
};
