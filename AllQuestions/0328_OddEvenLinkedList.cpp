#include <iostream>

/**
 * @brief Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has only one node, return
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* odd = head;           // Initialize odd pointer to the head of the list
        ListNode* even = head->next;    // Initialize even pointer to the second node
        ListNode* evenRoot = even;      // Store the start of the even list

        while (even != nullptr && even->next != nullptr) {
            // Update odd and even pointers to skip one node each
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        // Connect the end of the odd list to the start of the even list
        odd->next = evenRoot;

        return head;
    }
};

int main(void) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = s.oddEvenList(head);

    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}