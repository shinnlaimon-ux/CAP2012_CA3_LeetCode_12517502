/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == nullptr || head->next == nullptr){
            return false;
        }

        ListNode *oneStep = head;
        ListNode *twoStep = head;

        while(twoStep != nullptr && twoStep -> next != nullptr ){
            oneStep = oneStep-> next;
            twoStep = twoStep ->next->next;

            if(oneStep == twoStep){
                return true;
            }
        }
        return false;
    }
};
