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
    int pairSum(ListNode* head) {
        vector<int> stk;
        ListNode* current = head;
        int len = 0;
        int curr = 0;
        int max = 0;
        while(current != nullptr){
            len++;
            current = current->next;
        }
        current = head;
        while(current != nullptr){
            if(curr >= len/2){
                stk.push_back(current->val);
            }
            curr++;
            current = current->next;
        }
        current = head;
        curr = 0;
        while(curr < len/2){
            int sum = current->val + stk.back();
            if(sum > max){
                max = sum;
            }
            stk.pop_back();
            current = current->next;
            curr++;
        }
        return max;
    }
};