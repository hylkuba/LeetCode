#include <iostream>

/**
 * @brief Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the size of the list is less than 2, return the head
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        // 1 -- 2 -- 3 -- 4
        // 2 xx 1 || 4 xx 3

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        // Swap the first 2
        head = curr;
        head->next = prev;
        curr = head->next;
        curr->next = next;

        // Move the pointers
        prev = curr;
        if(curr->next == nullptr || curr->next->next == nullptr) {
            return head;
        }
        curr = curr->next;
        next = curr->next;
        
        while(curr != nullptr && next != nullptr) {
            //std::cout << "Prev: " << prev->val << " Curr: " << curr->val << " Next: " << next->val << std::endl;
            
            // Swap the current pair
            ListNode* tmp = next->next;
            prev->next = next;
            next->next = curr;
            curr->next = tmp;
            
            // Move the pointers
            prev = curr;
            if(curr->next == nullptr || curr->next->next == nullptr) {
                break;
            }
            curr = curr->next;
            next = curr->next;
        }

        return head;
    }
};

int main(void) {
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2));
    ListNode* result = s.swapPairs(head);
    printList(result);
    return 0;
}