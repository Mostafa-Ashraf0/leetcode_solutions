class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> count;

        ListNode* current = head;

        while (current != nullptr) {
            if (count.find(current) != count.end()) {
                return true;
            }

            count[current]++;
            current = current->next;
        }

        return false;
    }
};