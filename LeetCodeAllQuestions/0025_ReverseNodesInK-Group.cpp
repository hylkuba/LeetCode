#include <iostream>
#include <stack>

/**
 * @brief Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check the size of the list for first k-group
        ListNode* checkSize = head;
        int size = 0;
        while(checkSize != nullptr) {
            size++;
            checkSize = checkSize->next;
        }

        // If the list is too small, or the k-group is 1, return the head
        if(size < k || k == 1) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = nullptr;
        ListNode* curr = head;
        std::stack<ListNode*> stack;

        // Push first k-group of elements to stack
        int count = 0;
        while(curr != nullptr && count++ < k) {
            stack.push(curr);
            curr = curr->next;

            // Keep track of following Node in order to connect reversed list with the rest
            right = curr;
        }

        // For first k-group set the head appropriately
        head = stack.top();
        curr = head;
        stack.pop();

        // Reverse first k-group
        while(!stack.empty()) {
            curr->next = stack.top();
            curr = curr->next;
            stack.pop();
        }

        // Connect reversed k-group with the rest of the list where "right" points to first element
        curr->next = right;
        left = curr; // Set the value of "left" to be the last element of the reversed list before the next
                     // k-group that will be reversed
        curr = curr->next;
        if(curr == nullptr) {
            return head;
        }

        // Repeat for every k-group
        do {
            count = 0;

            // Push k elements into the stack
            while(curr != nullptr && count++ < k) {
                stack.push(curr);
                curr = curr->next;
                
                // Keep track of following Node in order to connect reversed list with the rest
                right = curr;
            }

            // If the next group of elements is too small, break the loop
            if(count < k || stack.empty()) {
                break;
            }

            // Connect previous group with the beggining of current reversed group
            left->next = stack.top();
            curr = left->next;
            stack.pop();

            // Add remaining elements of stack
            while(!stack.empty()) {
                curr->next = stack.top();
                curr = curr->next;
                stack.pop();
            }

            curr->next = right;
            left = curr;
            curr = curr->next;

        } while(right != nullptr);

        return head;
    }
};

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, 2);
    printList(newHead);

    return 0;
}