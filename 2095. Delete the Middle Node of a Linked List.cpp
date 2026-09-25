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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        //calculate size
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        temp = head;
        if(size == 1) return nullptr;

        ListNode* prev;
        for(int i = 0; i < size/2; i++){
            prev = temp;
            temp = temp->next;
        }
        ListNode* after = temp->next;
        prev->next = after;
        return head;
    }
};