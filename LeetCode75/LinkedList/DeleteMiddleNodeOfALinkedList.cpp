struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Check if there is just one node
        if(head->next == nullptr) return nullptr;

        ListNode* root = head;
        ListNode* prev = root;
        ListNode* middleNode = root;

        int totalCnt = 0;
        int middle = 0;

        while(head) {
            totalCnt++;

            int tmp = totalCnt / 2;  // No need to floor it, division of ints does it automatically
            if(tmp > middle) {
                middle = tmp;
                prev = middleNode;
                middleNode = middleNode->next;
            }

            head = head->next;
        }

        // Remove middle node
        prev->next = middleNode->next;

        return root;
    }
};