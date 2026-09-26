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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>digits;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        int digit = 0;
        int n;
        while(temp1 != nullptr || temp2 != nullptr){
            if(temp1 == nullptr){
                n = temp2->val + carry;
            }else if(temp2 == nullptr){
                n = temp1->val + carry;
            }else{
                n = temp1->val + temp2->val + carry;
            }
            digit = n % 10;
            digits.insert(digits.begin(), digit);
            carry = n / 10;
            if(temp1 == nullptr){
                temp2 = temp2->next;
            }else if(temp2 == nullptr){
                temp1 = temp1->next;
            }else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            } 
        }
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        ListNode* node = new ListNode(digits[digits.size()-1]);
        ListNode* rhead = node;
        ListNode* temp = rhead;
        ListNode* prev;
        for(int i = digits.size()-2; i >= 0; i--){
            ListNode* node = new ListNode(digits[i]);
            prev = temp;
            temp = node;
            prev->next = temp;
        }
        return rhead;
    }
};
