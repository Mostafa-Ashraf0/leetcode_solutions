/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> addressIndex;
        unordered_map<int, Node*> addressIndexCp;
        unordered_map<int, int> randomIndex;
        if(head == nullptr) return nullptr;
        int nodeIndex = 0;
        Node* temp = head;
        Node* nodeCp = new Node(head->val);
        Node* headCp = nodeCp;
        Node* prev = headCp;
        addressIndex[temp] = nodeIndex;
        nodeIndex++;
        temp = temp->next;
        //create the copy and fill rest of addressIndex 
        while(temp != nullptr){
            addressIndex[temp] = nodeIndex;
            Node* nodeCp = new Node(temp->val);
            Node* current = nodeCp;
            prev->next = current;
            prev = prev->next;
            temp = temp->next;
            nodeIndex++;
        }
        nodeIndex = 0;
        temp = head;
        //fill the randomIndex 
        while(temp != nullptr){
            int nIndex = addressIndex[temp];
            if (temp->random == nullptr) {
                randomIndex[nIndex] = -1;
            } else {
                randomIndex[nIndex] = addressIndex[temp->random];
            }
            temp = temp->next;
        }
        //fill the addressIndexCp
        Node* temp2 = headCp;
        while(temp2 != nullptr){
            addressIndexCp[nodeIndex] = temp2;
            nodeIndex++;
            temp2 = temp2->next;
        }
        nodeIndex = 0;
        temp2 = headCp;
        //map the random in copied List
        while(temp2 != nullptr){
            if (randomIndex[nodeIndex] == -1) {
                temp2->random = nullptr;
            } else {
                temp2->random = addressIndexCp[randomIndex[nodeIndex]];
            }
            nodeIndex++;
            temp2 = temp2->next;
        }
        return headCp;
    }
};
