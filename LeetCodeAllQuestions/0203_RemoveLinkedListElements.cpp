#include <iostream>

/**
 * @brief Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** @brief Dummy pointer solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(0, head);
        ListNode* dummy = ans;

        while (dummy != nullptr) {
            while (dummy->next != nullptr && dummy->next->val == val) {
                dummy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }

        return ans->next;        
    }
}; 
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = curr;

        // Deal with possible val on head value
        if(curr->val == val) {
            while(curr != nullptr && curr->val == val) {
                curr = curr->next;
            }

            if(curr == nullptr) {
                head = nullptr;
                return head;
            }

            head = curr;
        }

        while(curr != nullptr) {
            if(curr->val == val) {
                while(curr != nullptr && curr->val == val) {
                    curr = curr->next;
                }

                prev->next = curr;
                if(curr == nullptr) {
                    break;
                }
            }
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};

int main(void) {
    Solution sol;

    // Create list {1, 2}
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Call removeElements function, assuming we want to remove nodes with val = 1
    head = sol.removeElements(head, 2);

    // Print the list after removal operation
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    // Cleanup
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}