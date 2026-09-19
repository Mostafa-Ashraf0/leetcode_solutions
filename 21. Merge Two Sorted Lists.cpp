class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = nullptr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (temp1->val > temp2->val) {
            head = list2;
            temp2 = temp2->next;
            prev = list2;
        } else {
            head = list1;
            temp1 = temp1->next;
            prev = list1;
        }

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val > temp2->val) {
                current = temp2;
                temp2 = temp2->next;

                prev->next = current;
                prev = current;
            } else {
                current = temp1;
                temp1 = temp1->next;

                prev->next = current;
                prev = current;
            }
        }

        if (temp1 == nullptr)
            prev->next = temp2;

        if (temp2 == nullptr)
            prev->next = temp1;

        return head;
    }
};