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
    void reorderList(ListNode* head) {
       ListNode* first = head;
        while(first->next != nullptr){
            ListNode* last = first->next;
            ListNode* prev = first;
            ListNode* temp = first;
            while(last->next != nullptr){
                prev = last;
                last = last->next;
            }
            if(prev == first) break;

            first = first->next;
            temp->next = last;
            prev->next = nullptr;
            last->next = first;
        }
    }
};