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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
            ListNode* current = head;
            while(current != nullptr){
                size++;
                current = current->next;
            }
            if(size <= 1) return head;
            k %= size;
        while(k > 0){
            ListNode* first = head;
            ListNode* last = first->next;
            ListNode* prev = first;
            if(size == 2){
                head = last;
                last->next = first;
                first->next = nullptr;
                k--;
                continue;
            }
            while(last->next != nullptr){
                prev = last;
                last = last->next;
            }
            head = last;
            last->next = first;
            prev->next = nullptr;
            k--;
        }
        return head;
    }
};