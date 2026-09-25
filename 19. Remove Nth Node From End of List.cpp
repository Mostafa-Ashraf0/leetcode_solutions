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
        ListNode* current = head;
        ListNode* prev;
        ListNode* after = current->next;
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        if(size == 1){
            head = nullptr;
            return head;
        }
        if(size - n == 0){
            head = head->next;
            return head;
        }
        for(int i = 0; i < size - n; i++){
            prev = current;
            current = current->next;
            after = after->next;
        }
        prev->next = after;
        return head;
    }
};
